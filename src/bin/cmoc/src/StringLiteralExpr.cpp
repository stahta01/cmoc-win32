/*  $Id: StringLiteralExpr.cpp,v 1.7 2016/05/06 03:42:55 sarrazip Exp $

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

#include "StringLiteralExpr.h"

#include "TranslationUnit.h"

using namespace std;


StringLiteralExpr::StringLiteralExpr(const string &literal)
  : Tree(TranslationUnit::getTypeManager().getPointerToIntegral(BYTE_TYPE, true)),  // char *
    stringLiteral(literal),
    stringLabel()
{
}


/*virtual*/
StringLiteralExpr::~StringLiteralExpr()
{
}


string
StringLiteralExpr::getLiteral() const
{
    return stringLiteral;
}


string
StringLiteralExpr::getLabel() const
{
    return stringLabel;
}


void
StringLiteralExpr::setLabel(const string &newLabel)
{
    assert(newLabel.length() > 0);
    stringLabel = newLabel;
}


string
StringLiteralExpr::getArg() const
{
    // OS-9 note: PCR is used even under that platform because string literals
    // are emitted in the code segment. Therefore this expression does not need
    // to use the Y register.
    //
    return stringLabel + ",PCR";
}


string
StringLiteralExpr::getEscapedVersion() const
{
    assert(!stringLabel.empty());
    return TranslationUnit::instance().getEscapedStringLiteral(stringLabel);
}


/*virtual*/
CodeStatus
StringLiteralExpr::emitCode(ASMText &out, bool lValue) const
{
    if (lValue)
        return false;

    out.ins("LEAX", getArg(), getEscapedVersion());
    out.ins("TFR", "X,D");
    return true;
}


/*static*/
string
StringLiteralExpr::escape(const string &s)
{
    string::size_type len = s.length();
    string escaped = "\"";

    for (size_t i = 0; i < len; i++)
    {
        switch (s[i])
        {
            case '\0': escaped += "\\0"; break;
            case '\a': escaped += "\\a"; break;
            case '\b': escaped += "\\b"; break;
            case '\t': escaped += "\\t"; break;
            case '\n': escaped += "\\n"; break;
            case '\v': escaped += "\\v"; break;
            case '\f': escaped += "\\f"; break;
            case '\r': escaped += "\\r"; break;
            case '\'': escaped += "\\'"; break;
            case '\"': escaped += "\\\""; break;
            case '\\': escaped += "\\\\"; break;
            default  :
            {
                unsigned char u = (unsigned char) s[i];
                if (u < 32 || u > 126)
                {
                    char t[128];
                    snprintf(t, sizeof(t), "\\x%02X", u);
                    escaped += t;
                }
                else
                    escaped += s[i];
            }
        }
    }

    return escaped + "\"";
}


// Interprets the character(s) at s + i.
// If '\0' is seen, returns false.
// Otherwise, 'out' receives the interpreted character,
// and 'i' is advanced by 0, 1, or more characters.
//
// Example: i = 1; interpretStringLiteralPosition("z\x41%", i, ch);
// This puts 'A' in ch, advances 'i' by 4 (so that i becomes 5)
// and returns true to indicate that 'ch' has been filled.
//
static bool
interpretStringLiteralPosition(const char *s, size_t &i, char &out)
{
    char c = s[i];
    if (c == '\0')
        return false;
    if (c == '\\')
    {
        ++i;
        c = s[i];  // char following backslash
        switch (c)
        {
        case 'a' : out = '\a'; ++i; return true;
        case 'b' : out = '\b'; ++i; return true;
        case 't' : out = '\t'; ++i; return true;
        case 'n' : out = '\n'; ++i; return true;
        case 'v' : out = '\v'; ++i; return true;
        case 'f' : out = '\f'; ++i; return true;
        case 'r' : out = '\r'; ++i; return true;
        case '\'': out = '\''; ++i; return true;
        case '\"': out = '\"'; ++i; return true;
        case '\\': out = '\\'; ++i; return true;
        case 'x':
            {
                char accum = 0;
                for (++i; isxdigit(s[i]); ++i)
                {
                    c = tolower(s[i]);
                    char digit = (c <= '9' ? c - '0' : c - 'a' + 10);
                    accum = (accum << 4) | digit;
                }
                out = accum;
            }
            return true;
        case '0':
            {
                char accum = 0;
                for (++i; s[i] >= '0' && s[i] <= '7'; ++i)
                {
                    char digit = s[i] - '0';
                    accum = (accum << 3) | digit;
                }
                out = accum;
            }
            return true;
        default  : out = '\\'; return true;  // 'i' is not advanced here
        }
    }

    // Ordinary character.
    out = c;
    ++i;
    return true;
}


/*static*/
string
StringLiteralExpr::decodeEscapedLiteral(const char *s)
{
    string stringValue;

    // Advance through 's', converting one or more input characters
    // into a single output character at each iteration.
    //
    char ch = '\0';
    for (size_t i = 0; interpretStringLiteralPosition(s, i, ch); )
        stringValue += ch;

    //cout << "StringLiteralExpr::decodeEscapedLiteral: return {" << stringValue << "}\n";
    return stringValue;
}


// Emits FCC and FCB directives that represent the contents of 'value'.
// Ends with an FCB 0 directive that represents the C string terminator.
//
/*static*/
void
StringLiteralExpr::emitStringLiteralDefinition(ASMText &out, const string &value)
{
    enum State { LINE_START, IN_FCC };

    State state = LINE_START;
    stringstream buffer;
    for (size_t i = 0; i < value.length(); i++)
    {
        unsigned char u = value[i];
        if (u < ' ' || u > 126 || u == '\"' || u == '\\')  // if unprintable/special character:
        {
            switch (state)
            {
                case IN_FCC:
                    buffer << '\"';
                    out.ins("FCC", buffer.str());
                    buffer.str(std::string());  // clear the buffer
                    state = LINE_START;

                    /* nobreak */

                case LINE_START:
                    out.ins("FCB", wordToString(u, true));
                    break;
            }
        }
        else  // printable character:
        {
            switch (state)
            {
                case LINE_START:
                    buffer << '\"';
                    state = IN_FCC;
                    /* nobreak */
                case IN_FCC:
                    buffer << u;
                    break;
            }
        }
    }

    if (state == IN_FCC)
    {
        buffer << '\"';
        out.ins("FCC", buffer.str());
    }

    out.ins("FCB", "0");
}
