/*  $Id: IdentifierExpr.h,v 1.4 2016/05/06 03:42:55 sarrazip Exp $

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

#ifndef _H_IdentifierExpr
#define _H_IdentifierExpr

#include "Tree.h"


class IdentifierExpr : public Tree
{
public:

    IdentifierExpr(const char *id);

    virtual ~IdentifierExpr();

    std::string getId() const;

    virtual CodeStatus emitCode(ASMText &out, bool lValue) const;

private:

    // Forbidden:
    IdentifierExpr(const IdentifierExpr &);
    IdentifierExpr &operator = (const IdentifierExpr &);

private:

    std::string identifier;

};


#endif  /* _H_IdentifierExpr */
