/*  $Id: IdentifierExpr.cpp,v 1.5 2016/05/06 03:42:54 sarrazip Exp $

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

#include "IdentifierExpr.h"

#include "VariableExpr.h"

using namespace std;


IdentifierExpr::IdentifierExpr(const char *id)
  : Tree(),
    identifier(id)
{
}


/*virtual*/
IdentifierExpr::~IdentifierExpr()
{
}


string
IdentifierExpr::getId() const
{
    return identifier;
}


/*virtual*/
CodeStatus
IdentifierExpr::emitCode(ASMText & /*out*/, bool /*lValue*/) const
{
    assert(false);
    return false;
}
