/*  $Id: FuncAddrExpr.cpp,v 1.8 2016/05/06 03:42:54 sarrazip Exp $

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

#include "FuncAddrExpr.h"

#include "TranslationUnit.h"
#include "FunctionDef.h"
#include "SemanticsChecker.h"

using namespace std;


FuncAddrExpr::FuncAddrExpr(const string &_id)
  : Tree(TranslationUnit::getTypeManager().getPointerToIntegral(BYTE_TYPE, true)),
    id(_id)
{
    assert(!id.empty());
}


/*virtual*/
FuncAddrExpr::~FuncAddrExpr()
{
}


/*virtual*/
void
FuncAddrExpr::checkSemantics(Functor &f)
{
    FunctionDef *fd = TranslationUnit::instance().getFunctionDef(id);
    if (fd == NULL)
    {
        errormsg("taking address of unknown function %s", id.c_str());
        return;
    }

    // Register this expression as if the current function were calling 'id'.
    // (If the expression is a global variable initializer, we consider main() to be
    // the caller, even though it is the compiler generated driver that calls it.)
    // This is for the purposes of determining which functions are never called
    // and do not need to have assembly code emitted for them.
    // See TranslationUnit::detectCalledFunctions().
    //
    SemanticsChecker &sem = dynamic_cast<SemanticsChecker &>(f);
    TranslationUnit &tu = TranslationUnit::instance();
    const FunctionDef *curFD = sem.getCurrentFunctionDef();
    if (!curFD)
        curFD = tu.getFunctionDef("main");
    assert(curFD);
    tu.registerFunctionCall(curFD->getId(), id);
}


string
FuncAddrExpr::getId() const
{
    assert(!id.empty());
    return id;
}


string
FuncAddrExpr::getLoadArgument() const
{
    FunctionDef *fd = TranslationUnit::instance().getFunctionDef(id);
    if (fd == NULL)
        return string();  // should have been detected by checkSemantics()

    return fd->getLabel() + ",PCR";
}


/*virtual*/
CodeStatus
FuncAddrExpr::emitCode(ASMText &out, bool lValue) const
{
    if (lValue)
    {
        assert(!"function address operator used as l-value");
        return false;
    }

    string arg = getLoadArgument();
    if (arg.empty())
        return false;
    out.ins("LEAX", arg, "take address of " + id + "()");
    out.ins("TFR", "X,D");

    return true;
}
