/*  $Id: VariableExpr.cpp,v 1.9 2016/06/08 02:47:56 sarrazip Exp $

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

#include "VariableExpr.h"

#include "TranslationUnit.h"
#include "Declaration.h"
#include "Scope.h"
#include "FunctionDef.h"
#include "FuncAddrExpr.h"

using namespace std;


VariableExpr::VariableExpr(const string &_id)
  : Tree(),
    id(_id),
    declaration(NULL),
    _isFuncAddrExpr(false)
{
    assert(!id.empty());
}


/*virtual*/
VariableExpr::~VariableExpr()
{
}


string
VariableExpr::getId() const
{
    assert(!id.empty());
    return id;
}


string
VariableExpr::getFrameDisplacementArg(int16_t offset) const
{
    assert(!_isFuncAddrExpr);
    if (declaration == NULL)
    {
        assert(false);
        return "";
    }
    return declaration->getFrameDisplacementArg(offset);
}


const Declaration *
VariableExpr::getDeclaration() const
{
    return declaration;
}


void
VariableExpr::setDeclaration(Declaration *decl)
{
    declaration = decl;
}


bool
VariableExpr::iterate(Functor &f)
{
    if (!f.open(this))
        return false;
    if (!f.close(this))
        return false;
    return true;
}


/*virtual*/
CodeStatus
VariableExpr::emitCode(ASMText &out, bool lValue) const
{
    assert(declaration != NULL && !_isFuncAddrExpr);

    if (getType() == ARRAY_TYPE)
    {
        if (lValue)
        {
            errormsg("array variable has no l-value");
            return true;
        }

        out.ins("LEAX", getFrameDisplacementArg(), "address of array " + getId());
        out.ins("TFR", "X,D", "as r-value");
        return true;
    }
    else if (getType() == CLASS_TYPE && !lValue)
    {
        errormsg("cannot use variable `%s', of type struct `%s', as an r-value",
                getId().c_str(), getTypeDesc()->className.c_str());
        return true;
    }

    assert(declaration != NULL);
    out.ins(
            (lValue ? "LEAX" : getLoadInstruction(getType())),
            getFrameDisplacementArg(),
            "variable " + getId() + ", declared at " + declaration->getLineNo());

    return true;
}
