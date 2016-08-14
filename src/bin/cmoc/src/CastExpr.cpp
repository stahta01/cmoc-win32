/*  $Id: CastExpr.cpp,v 1.5 2016/05/06 03:42:54 sarrazip Exp $

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

#include "CastExpr.h"

#include "TranslationUnit.h"
#include "VariableExpr.h"
#include "Declaration.h"
#include "WordConstantExpr.h"
#include "VariableExpr.h"
#include "IdentifierExpr.h"

#include <assert.h>

using namespace std;


// Does not keep a reference to 'td'.
// Keeps a copy of pointer 'e'.
//
CastExpr::CastExpr(const TypeDesc *td, Tree *e)
  : Tree(td),
    subExpr(e)
{
    assert(subExpr != NULL);
    IdentifierExpr *ie = dynamic_cast<IdentifierExpr *>(subExpr);
    if (ie != NULL)
    {
        subExpr = new VariableExpr(ie->getId());
        subExpr->copyLineNo(*ie);
        delete ie;
    }
}


/*virtual*/
CastExpr::~CastExpr()
{
    delete subExpr;
}


const Tree *
CastExpr::getSubExpr() const
{
    assert(subExpr != NULL);
    return subExpr;
}


Tree *
CastExpr::getSubExpr()
{
    assert(subExpr != NULL);
    return subExpr;
}


/*virtual*/
CodeStatus
CastExpr::emitCode(ASMText &out, bool lValue) const
{
    assert(getType() != CLASS_TYPE);
    assert(subExpr != NULL);

    if (!subExpr->emitCode(out, lValue))
        return false;

    const TypeDesc *castTD = getTypeDesc();
    const TypeDesc *subTD = subExpr->getTypeDesc();
    if (castTD->type == VOID_TYPE || subTD == castTD)
        return true;

    if (subTD->type == BYTE_TYPE && castTD->type != BYTE_TYPE)
    {
        // We are casting to a 2-byte type.
        const char *extendIns = (subTD->isSigned ? "SEX" : "CLRA");  // as in C
        out.ins(extendIns, "", "cast from byte");
        return true;
    }

    return true;
}


bool
CastExpr::iterate(Functor &f)
{
    if (!f.open(this))
        return false;
    if (!subExpr->iterate(f))
        return false;
    if (!f.close(this))
        return false;
    return true;
}
