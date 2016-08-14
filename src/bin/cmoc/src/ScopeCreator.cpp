/*  $Id: ScopeCreator.cpp,v 1.7 2016/04/11 03:26:59 sarrazip Exp $

    CMOC - A C-like cross-compiler
    Copyright (C) 2003-2015 Pierre Sarrazin <http://sarrazip.com/>

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

#include "ScopeCreator.h"

#include "TranslationUnit.h"
#include "CompoundStmt.h"
#include "ForStmt.h"
#include "WhileStmt.h"
#include "DeclarationSequence.h"
#include "VariableExpr.h"
#include "FunctionCallExpr.h"

using namespace std;


ScopeCreator::ScopeCreator(TranslationUnit &tu, Scope *ancestorScope)
:   translationUnit(tu)
{
    translationUnit.pushScope(ancestorScope);
}


ScopeCreator::~ScopeCreator()
{
    translationUnit.popScope();
}


// If 't' is a statement that creates a scope, creates a Scope object, makes it
// the scope of 't', and pushes that scope onto that global scope stack.
//
// If 't' is a DeclarationSequence, calls declareVariable() on the current scope
// for each Declaration in the sequence.
//
// If 't' is a VariableExpr, calls processVariableExpr() on it.
//
// If 't' is a FunctionCallExpr and the function name is actually a variable name,
// tells the FunctionCallExpr about the Declaration of that variable.
//
bool
ScopeCreator::open(Tree *t)
{
    Scope *cs = translationUnit.getCurrentScope();
    assert(cs != NULL);

    // Compound statements create a scope.
    // So do the for() and while() statement bodies.
    //
    if (   dynamic_cast<CompoundStmt *>(t)
        || dynamic_cast<ForStmt *>(t)
        || dynamic_cast<WhileStmt *>(t))
    {
        Scope *s = new Scope(cs);
        assert(s->getParent() == cs);

        s->copyLineNo(*t);  // to help debugging

        // Note: 'cs' is now owner of 's', i.e., destroying 'cs' will call delete on 's'.

        t->setScope(s);
        t->pushScopeIfExists();
    }

    DeclarationSequence *declSeq = dynamic_cast<DeclarationSequence *>(t);
    if (declSeq != NULL)
    {
        for (std::vector<Tree *>::iterator it = declSeq->begin(); it != declSeq->end(); ++it)
        {
            if (Declaration *decl = dynamic_cast<Declaration *>(*it))
            {
                /*cout << "ScopeCreator::open(" << t << "): Declaration: " << decl->getVariableId()
                        << " at line " << decl->getLineNo()
                        << ", cs=" << cs << "\n";*/
                if (!cs->declareVariable(decl))
                {
                    const Declaration *existingDecl = cs->getVariableDeclaration(decl->getVariableId(), false);
                    assert(existingDecl);
                    decl->errormsg("variable `%s' already declared in this scope at %s",
                                   decl->getVariableId().c_str(), existingDecl->getLineNo().c_str());
                }
            }
            else
                (*it)->errormsg("invalid declaration");
        }
    }

    VariableExpr *ve = dynamic_cast<VariableExpr *>(t);
    if (ve != NULL)
    {
        processVariableExpr(*ve);
        return true;
    }

    FunctionCallExpr *fce = dynamic_cast<FunctionCallExpr *>(t);
    if (fce)
    {
        // Process a call through a pointer. Note that we can't call isCallThroughPointer()
        // on 'fce' yet because that method relies on FunctionCallExpr::funcPtrVarDecl,
        // which is the member we are going to initialize here.
        //
        string id = fce->getIdentifier();  // empty if call is not through identifier, e.g., (*pf)() or obj.member()
        Declaration *decl = cs->getVariableDeclaration(id, true);
        if (decl != NULL)
        {
            FunctionDef *fd = TranslationUnit::instance().getFunctionDef(id);
            if (fd != NULL)
            {
                fce->warnmsg("calling '%s', which is both a variable and a function name", id.c_str());
                return true;
            }
            else
            {
                const TypeDesc *declTD = decl->getTypeDesc();
                if (declTD->type != POINTER_TYPE || declTD->pointedTypeDesc->type != VOID_TYPE)
                {
                    fce->warnmsg("variable '%s' used as function pointer without being of type void *", id.c_str());
                }
            }
        }

        fce->setFunctionPointerVariableDeclaration(decl);
        return true;
    }

    return true;
}


bool
ScopeCreator::close(Tree *t)
{
    t->popScopeIfExists();
    return true;
}


// If 've' is a variable declared in the current scope (or an ancestor scope),
// tells 've' about the found Declaration.
// If 've' is instead a function name, tells 've' that it is a
// function address expression.
// Declares an error message otherwise.
//
void
ScopeCreator::processVariableExpr(VariableExpr &ve)
{
    string id = ve.getId();
    Scope *cs = translationUnit.getCurrentScope();
    assert(cs);
    Declaration *decl = cs->getVariableDeclaration(id, true);
    if (decl != NULL)
    {
        //cerr << "    decl at " << decl->getLineNo() << endl;
        ve.setDeclaration(decl);

        assert(decl->getType() != VOID_TYPE);
        ve.setTypeDesc(decl->getTypeDesc());
        return;
    }

    const FunctionDef *fd = translationUnit.getFunctionDef(id);
    if (fd != NULL)
    {
        ve.markAsFuncAddrExpr();
        return;
    }

    ve.errormsg("undeclared variable `%s'", ve.getId().c_str());
}
