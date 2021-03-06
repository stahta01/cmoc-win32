/*  $Id: AssemblerStmt.cpp,v 1.15 2016/10/05 02:28:23 sarrazip Exp $

    CMOC - A C-like cross-compiler
    Copyright (C) 2003-2016 Pierre Sarrazin <http://sarrazip.com/>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "AssemblerStmt.h"

#include "TranslationUnit.h"
#include "SemanticsChecker.h"
#include "ASMText.h"

using namespace std;


const char AssemblerStmt::variableNameEscapeChar = ':';


AssemblerStmt::AssemblerStmt(const std::string &ins,
                                const std::string &arg,
                                bool _argIsVariable)
  : Tree(),
    asmText(),
    instruction(ins),
    argument(arg),
    scopeOfAsmOnlyFunction(NULL),
    argIsVariable(_argIsVariable)
{
    if (instruction.length() < 3 || instruction.length() > 5)
        errormsg("invalid assembler instruction");
}


AssemblerStmt::AssemblerStmt(const char *_asmText)
  : Tree(),
    asmText(_asmText),
    instruction(),
    argument(),
    scopeOfAsmOnlyFunction(NULL),
    argIsVariable(false)
{
}


AssemblerStmt::~AssemblerStmt()
{
}


void
AssemblerStmt::setAssemblyOnly(const Scope *functionScope)
{
    assert(functionScope);
    scopeOfAsmOnlyFunction = functionScope;
}


// Parse a newline, whitespace sequence or word at offset 'i' in 'text'.
// Returns END if 'i' is at the end of the string.
// Returns the text of the parsed token (empty string for END).
// Advances 'i' to the character past the parsed token.
// (No advancement in the case of END.)
//
// Quirk: text of the form [var] is considered as 3 tokens: "[", "var" and "]",
// but foo[bar] is considered as a single token.
// The first rule facilitates the parsing of indirect addresses,
// e.g., "jsr [someVariable]".
// The second rule allows to parse an array reference as a single token, e.g.,
// "ldd someIntegerArray[12]".
//
// A variable name may be precedes by an escape character (given by variableNameEscapeChar).
// This is useful when the name is that of a register. The escape character forces the name
// to refer to the variable instead of the register.
//
AssemblerStmt::Token
AssemblerStmt::getToken(const string &text, size_t &i, string &tokenText)
{
    tokenText.clear();

    if (i >= text.length())
    {
        tokenText = "";
        return END;
    }
    if (text[i] == '\n')
    {
        ++i;  // pass the newline
        tokenText = "\n";
        return NEWLINE;
    }

    tokenText = text[i];

    // Parse a sequence of white space, or of non-space characters.
    // Such a sequence stops before a ']', which is considered a word by itself.
    //
    bool isFirstCharSpace = isspace(text[i]);
    ++i;  // pass 1st char of token
    if (isFirstCharSpace)
    {
        for ( ; i < text.length() && text[i] != '\n' && isspace(text[i]); ++i)  // accumulate sequence of spaces
            tokenText += text[i];
        return WHITESPACE;
    }

    if (!isAssemblyIdentifierChar(text[i - 1]) && text[i - 1] != variableNameEscapeChar)
    {
        // The character cannot be part of an identifier, so it is considered as a single-character token.
        // Note that '@' can be part of an assembler identifier (this is supported by LWASM).
        return WORD;
    }

    // If '[' is encountered, we want to accumulate all chars up to and including "]",
    // because this is the "foo[bar]" case.
    // If no '[' is encountered, we want to stop before the "]",
    // because this is the "[var]" case.
    //
    bool gotOpeningBracket = false;
    for ( ; ; ++i)
    {
        if (i == text.length())  // stop on end of text
            break;
        if (isspace(text[i]))  // stop on white space
            break;
        if (text[i] == ']' && !gotOpeningBracket)
            break;
        if (text[i] == '[')  // remember this
            gotOpeningBracket = true;
        else if (!gotOpeningBracket && !isAssemblyIdentifierChar(text[i]))  // stop on '+', '-' etc.
            break;
        tokenText += text[i];
    }

    return WORD;
}


// Removes C++-style comments (ends of lines that start with two slashes).
//
string
AssemblerStmt::removeComments(const string &text)
{
    string result;
    size_t origLen = text.length();
    for (size_t i = 0; i < origLen; ++i)
    {
        if (text[i] == '/' && i + 1 < origLen && text[i + 1] == '/')  // if '//' comment
        {
            for (i += 2; i < origLen && text[i] != '\n'; ++i)
                ;
            if (i == origLen)
                break;
            --i;  // compensate for for-loop increment; next iteration will append \n to 'result'
        }
        else
            result += text[i];
    }
    return result;
}


// Returns true if tokenText is of the form xxx[yyy], with yyy in decimal.
// In this case, also returns the xxx string in 'variableName'
// and yyy (converted to a signed integer) in 'offset'.
// Does not guarantee that xxx is a known variable name.
// Otherwise, returns false.
//
bool
AssemblerStmt::parseVariableNameAndOffset(const string &tokenText, string &variableName, int16_t &offset)
{
    offset = 0;

    size_t tokenLen = tokenText.length();
    if (tokenLen < 4 || tokenText[tokenLen - 1] != ']')
        return false;

    size_t i;
    for (i = tokenLen - 1; i > 0 && tokenText[i - 1] != '['; --i)
        ;
    if (i == 0)
        return false;  // closing bracket found, but not opening bracket: fail
    if (i == 1)
        return false;  // closing bracket found at beginning of tokenText: fail
    if (i == tokenLen - 1)
        return false;  // nothing inside bracket: fail

    // 'i' points to first char of decimal string.
    long n = atol(tokenText.c_str() + i);
    if (n < -32768 || n > 32767)
        return false;  // overflow: fail

    offset = int16_t(n);
    variableName = tokenText.substr(0, i - 1);
    return true;
}


// Processes assembly language text.
// Resolves each 3rd column name to a program variable, if any.
// If a name in the 3rd column is not a program variable, it is left as is,
// without error or warning.
// Returns the resulting text.
//
// text: Must not contain comments.
// scope: Scope object to use to resolve variable names.
// recognizedVarNames: If not null, the set accumulates the names of declared
//                     C variables that were referred to in 'text'.
//                     (Does not accumulate enumerated names.)
// requireAllocatedVariables: Require the variables used by the assembly code
//                            to have received a valid frame displacement.
//                            Must only be set to true when the returned text
//                            will not be used in the final emitted code.
//
string
AssemblerStmt::resolveVariableReferences(const string &text,
                                         const Scope &scope,
                                         set<string> *recognizedVarNames,
                                         bool requireAllocatedVariables)
{
    string result;

    size_t colNum = 1;  // 1 = label column, 2 = instr. col., 3 = arg. col.
    Token tok = END;
    string tokenText, lastCol2;
    size_t i = 0;  // offset in 'text'
    bool currentInstructionCanRefVariables = false;

    while ((tok = getToken(text, i, tokenText)) != END)
    {
        switch (tok)
        {
        case NEWLINE:
            colNum = 1;
            result += tokenText;
            break;

        case WHITESPACE:
            ++colNum;
            result += tokenText;
            break;

        case WORD:
            if (colNum == 3 && currentInstructionCanRefVariables)  // if instruction argument that could refer to variable or enum
            {
                int16_t offset = 0;
                string variableName;
                if (!parseVariableNameAndOffset(tokenText, variableName, offset))
                    variableName = tokenText;

                // If a C variable name escape is used, remove it.
                string unescapedVariableName = variableName;
                if (variableName.length() > 0 && variableName[0] == variableNameEscapeChar)
                    unescapedVariableName.erase(0, 1);

                const Declaration *variableDecl = scope.getVariableDeclaration(unescapedVariableName, true);

                uint16_t enumValue = 0;

                if (isRegisterName(variableName))
                {
                    result += tokenText;  // no substitution allowed on register name
                }
                else if (variableDecl != NULL)
                {
                    if (requireAllocatedVariables)
                        result += variableDecl->getFrameDisplacementArg(offset);

                    if (recognizedVarNames != NULL)
                        recognizedVarNames->insert(unescapedVariableName);
                }
                else if (FunctionDef *fd = TranslationUnit::instance().getFunctionDef(tokenText))
                {
                    // Replace the function name with its assembly label.
                    //
                    result += fd->getLabel();
                    if (lastCol2 != "bsr" && lastCol2 != "lbsr"
                            && lastCol2 != "bra" && lastCol2 != "lbra"
                            && lastCol2 != "brn" && lastCol2 != "lbrn"
                            && ! ASMText::isConditionalBranch(lastCol2.c_str()))
                        result += ",pcr";

                    // Find which function is calling 'fd', i.e., the function containing the asm{}.
                    // First, go up the parents of 'scope' until a direct child of the global scope.
                    // This child is the scope of a function. Find the function whose scope this is.
                    //
                    const Scope &globalScope = TranslationUnit::instance().getGlobalScope();
                    const Scope *callerScope = &scope;
                    while (callerScope->getParent() != &globalScope)
                        callerScope = callerScope->getParent();
                    const FunctionDef *caller = TranslationUnit::instance().getFunctionDefFromScope(*callerScope);
                    assert(caller);

                    // Register the function call.
                    //
                    fd->setCalled(); // make sure the code for 'fd' gets emitted
                    TranslationUnit::instance().registerFunctionCall(caller->getId(), fd->getId());
                }
                else if (TranslationUnit::getTypeManager().getEnumeratorValue(unescapedVariableName, enumValue))
                {
                    result += wordToString(enumValue);
                }
                else  // no match: keep text as is
                {
                    result += tokenText;
                }
            }
            else
            {
                result += tokenText;

                if (colNum == 2)  // if instruction field
                {
                    stringToLower(tokenText);
                    lastCol2 = tokenText;

                    // A push/pull instruction's argument must never be interpreted as
                    // a C variable name. A C function could have an argument called 'x'
                    // but "pshs x" still refers to register X.
                    //
                    currentInstructionCanRefVariables = (tokenText != "pshs"
                                                      && tokenText != "puls"
                                                      && tokenText != "pshu"
                                                      && tokenText != "pulu");
                }
            }
            break;

        case END:
        default:
            assert(!"unexpected");
        }
    }

    return result;
}


bool
AssemblerStmt::isGlobalVariable(const string &varName)
{
    const Scope &globalScope = TranslationUnit::instance().getGlobalScope();
    const Declaration *varDecl = globalScope.getVariableDeclaration(varName, false);
    return varDecl != NULL;
}


/*virtual*/
void
AssemblerStmt::checkSemantics(Functor &f)
{
    // Get the parent function.
    //
    SemanticsChecker &checker = dynamic_cast<SemanticsChecker &>(f);
    const FunctionDef *parentFunctionDef = checker.getCurrentFunctionDef();
    assert(parentFunctionDef != NULL);
    assert(parentFunctionDef->getScope() != NULL);

    if (asmText.empty())
    {
        if (parentFunctionDef->isAssemblyOnly() && argIsVariable && !isGlobalVariable(argument))
            errormsg("assembly-only function refers to local C variable `%s'", argument.c_str());
    }
    else  // if multi-line assembly language text
    {
        // Resolve variable (and function) references in the text.
        // This is necessary to register function calls made in that text
        // (via FunctionDef::setCalled() and TranslationUnit::registerFunctionCall()).
        //
        set<string> recognizedVarNames;
        const Scope *scope = (scopeOfAsmOnlyFunction ? scopeOfAsmOnlyFunction : parentFunctionDef->getScope());
        assert(scope);
        (void) resolveVariableReferences(removeComments(asmText), *scope, &recognizedVarNames, false);

        // An assembly-only function is not allowed to refer to local C variables because such a function
        // has no stack frame. (It is allowed to call functions however.)
        //
        if (parentFunctionDef->isAssemblyOnly() && recognizedVarNames.size() > 0)
        {
            // Create and issue an error message.
            stringstream enumeration;
            size_t numLocals = 0;
            for (set<string>::const_iterator it = recognizedVarNames.begin(); it != recognizedVarNames.end(); ++it)
            {
                string varName = *it;
                if (isGlobalVariable(varName))
                    continue;  // allow asm{} text to refer to globals
                if (numLocals > 0)
                    enumeration << ", ";
                enumeration << "`" << varName << "'";
                ++numLocals;
            }
            if (numLocals > 0)
                errormsg("assembly-only function refers to local C variable%s %s",
                         numLocals > 1 ? "s" : "", enumeration.str().c_str());
        }
    }
}


/*virtual*/
CodeStatus
AssemblerStmt::emitCode(ASMText &out, bool lValue) const
{
    if (lValue)
        return false;

    if (!asmText.empty())  // if multi-line assembly language text instead of single instruction:
    {
        const Scope *cs = TranslationUnit::instance().getCurrentScope();
        assert(cs);
        string resolvedAsmText = resolveVariableReferences(removeComments(asmText), *cs, NULL, true);
        out.emitInlineAssembly(resolvedAsmText);
        return true;
    }

    Declaration *variableDecl = NULL;
    if (argIsVariable)
    {
        Scope *cs = TranslationUnit::instance().getCurrentScope();
        variableDecl = cs->getVariableDeclaration(argument, true);

        if (variableDecl == NULL)
            errormsg("undeclared variable `%s' used in inline assembler statement",
                        argument.c_str());
    }

    string comment = getLineNo() + ": " + inlineASMTag;

    if (variableDecl != NULL)
        out.ins(instruction, variableDecl->getFrameDisplacementArg(), comment + " re: variable " + argument);
    else
        out.ins(instruction, argument, comment);
    return true;
}
