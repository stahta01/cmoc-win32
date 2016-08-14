/*  $Id: TypeManager.h,v 1.9 2016/06/21 01:06:13 sarrazip Exp $

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

#ifndef _H_TypeManager
#define _H_TypeManager

#include "TypeDesc.h"

#include <vector>
#include <map>

class Declarator;


class TypeManager
{
public:

    TypeManager();

    ~TypeManager();

    const TypeDesc *getVoidType() const;

    const TypeDesc *getIntType(BasicType byteOrWordType, bool isSigned) const;

    const TypeDesc *getSizelessType(bool isSigned) const;  // for 'signed' and 'unsigned'

    const TypeDesc *getPointerTo(const TypeDesc *td) const;

    const TypeDesc *getPointerTo(const TypeDesc *td, size_t level) const;

    const TypeDesc *getPointerToIntegral(BasicType byteOrWordType, bool isSigned) const;

    const TypeDesc *getPointerToVoid() const;

    const TypeDesc *getArrayOf(const TypeDesc *td, size_t numArrayDimensions) const;

    const TypeDesc *getSizedArrayOf(const TypeDesc *td, const std::vector<uint16_t> &arrayDimensions, size_t dimIndex) const;

    // isUnion: false for a struct.
    // createIfAbsent: If false, returns NULL if the className is not found.
    //
    const TypeDesc *getClassType(const std::string &className, bool isUnion, bool createIfAbsent) const;

    const TypeDesc *getFunctionPointerType() const;

    bool addTypeDef(const TypeDesc *declSpecTypeDef, Declarator *declarator);

    const TypeDesc *getTypeDef(const char *id) const;

private:

    typedef std::map<std::string, const TypeDesc *> TypeDefMap;  // key: typedef name; value: type defined in types[]

    mutable std::vector<TypeDesc *> types;  // see the constructor for predefined types
    TypeDefMap typeDefs;

};


#endif  /* _H_TypeManager */
