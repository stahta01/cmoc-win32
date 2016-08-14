/*  $Id: DeclarationSpecifierList.h,v 1.5 2016/06/29 18:40:53 sarrazip Exp $

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

#ifndef _H_DeclarationSpecifierList
#define _H_DeclarationSpecifierList

#include "util.h"


class DeclarationSpecifierList
{
public:

    enum Specifier
    {
        TYPEDEF_SPEC,
        INTERRUPT_SPEC,
        ASSEMBLY_ONLY_SPEC,
        EXTERN_SPEC,
        STATIC_SPEC,
    };

    DeclarationSpecifierList();

    void add(const TypeDesc *td);

    void add(Specifier specifier);

    const TypeDesc *getTypeDesc() const;

    bool isInterruptServiceFunction() const;

    bool isAssemblyOnly() const;

    bool isTypeDefinition() const;

    bool isExternDeclaration() const;

    bool isStaticDeclaration() const;

    bool isModifierLegalOnVariable() const;

private:

    const TypeDesc *typeDesc;  // not owned by this class
    bool isTypeDef;
    bool isISR;
    bool asmOnly;
    bool isExtern;
    bool isStatic;

};


#endif  /* _H_DeclarationSpecifierList */
