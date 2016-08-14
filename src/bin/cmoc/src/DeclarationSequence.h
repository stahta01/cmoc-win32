/*  $Id: DeclarationSequence.h,v 1.3 2015/06/28 05:04:29 sarrazip Exp $

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

#ifndef _H_DeclarationSequence
#define _H_DeclarationSequence

#include "TreeSequence.h"
#include "Declarator.h"
#include "Declaration.h"
#include "FunctionDef.h"
#include "DeclarationSpecifierList.h"


class DeclarationSequence : public TreeSequence
{
public:

    DeclarationSequence(const TypeDesc *_typeDesc);

    virtual ~DeclarationSequence();

    // Adds a Declaration object to this sequence.
    // This Declaration object is built from this sequence's TypeDesc
    // and from 'declarator'.
    //
    // Finishes by calling delete on 'declarator'.
    //
    void processDeclarator(Declarator *declarator, const DeclarationSpecifierList &dsl);

};


#endif  /* _H_DeclarationSequence */
