/*  $Id: FuncAddrFixer.h,v 1.1 2016/04/10 19:23:53 sarrazip Exp $

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

#ifndef _H_FuncAddrFixer
#define _H_FuncAddrFixer

#include "FuncAddrExpr.h"

// Functor used in an iteration that finds all variable expressions
// that are marked as taking the address of a function. For each
// instance found, its direct parent is asked to destroy the instance
// and to replace it with a FuncAddrExpr.
//
// This requires that any class derived from Tree that could have a
// VariableExpr has a direct member (e.g., BinaryOpExpr, SwitchStmt,
// etc.) override Tree::replaceChild().
//
class FuncAddrFixer : public Tree::Functor
{
public:
    FuncAddrFixer() : ancestors() { ancestors.reserve(128); }

    virtual ~FuncAddrFixer() {}

    virtual bool open(Tree *t)
    {
        ancestors.push_back(t);
        return true;
    }

    virtual bool close(Tree *t)
    {
        ancestors.pop_back();

        if (VariableExpr *ve = dynamic_cast<VariableExpr *>(t))
            if (ve->isFuncAddrExpr() && ancestors.size() > 0)
            {
                FuncAddrExpr *fae = new FuncAddrExpr(ve->getId());
                fae->copyLineNo(*ve);  // useful in case of error message
                ancestors.back()->replaceChild(ve, fae);
            }

        return true;
    }

private:
    std::vector<Tree *> ancestors;
};


#endif  /* _H_FuncAddrFixer */
