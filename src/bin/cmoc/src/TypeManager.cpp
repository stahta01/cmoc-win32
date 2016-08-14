/*  $Id: TypeManager.cpp,v 1.9 2016/06/21 01:06:13 sarrazip Exp $

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

#include "TypeManager.h"

#include "util.h"
#include "Declarator.h"


using namespace std;


TypeManager::TypeManager()
:   types(),
    typeDefs()
{
    // The order is significant. See the other methods.
    types.push_back(new TypeDesc(VOID_TYPE, NULL, string(), false, false));
    types.push_back(new TypeDesc(BYTE_TYPE, NULL, string(), false, false));
    types.push_back(new TypeDesc(BYTE_TYPE, NULL, string(), true, false));
    types.push_back(new TypeDesc(WORD_TYPE, NULL, string(), false, false));
    types.push_back(new TypeDesc(WORD_TYPE, NULL, string(), true, false));
    types.push_back(new TypeDesc(SIZELESS_TYPE, NULL, string(), false, false));
    types.push_back(new TypeDesc(SIZELESS_TYPE, NULL, string(), true, false));
}


TypeManager::~TypeManager()
{
    for (vector<TypeDesc *>::iterator it = types.begin(); it != types.end(); ++it)
        delete *it;
}


const TypeDesc *
TypeManager::getVoidType() const
{
    return types[0];
}


const TypeDesc *
TypeManager::getIntType(BasicType byteOrWordType, bool isSigned) const
{
    if (byteOrWordType == BYTE_TYPE)
        return types[isSigned ? 2 : 1];
    if (byteOrWordType == WORD_TYPE)
        return types[isSigned ? 4 : 3];
    assert(false);
    return NULL;
}


const TypeDesc *
TypeManager::getSizelessType(bool isSigned) const
{
    return types[isSigned ? 6 : 5];
}


const TypeDesc *
TypeManager::getPointerTo(const TypeDesc *pointedTypeDesc) const
{
    if (pointedTypeDesc == NULL)
        return NULL;

    for (vector<TypeDesc *>::const_iterator it = types.begin(); it != types.end(); ++it)
    {
        const TypeDesc *td = *it;
        assert(td && td->isValid());
        if (td->type == POINTER_TYPE && td->pointedTypeDesc == pointedTypeDesc)
            return td;
    }

    types.push_back(new TypeDesc(POINTER_TYPE, pointedTypeDesc, string(), false, false));
    return types.back();
}


// Example: getPointerTo([byte], 3) will return byte ***.
// Level zero means typeDesc itself.
//
const TypeDesc *
TypeManager::getPointerTo(const TypeDesc *typeDesc, size_t level) const
{
    for ( ; level > 0; --level)
        typeDesc = getPointerTo(typeDesc);
    return typeDesc;
}


const TypeDesc *
TypeManager::getPointerToIntegral(BasicType byteOrWordType, bool isSigned) const
{
    return getPointerTo(getIntType(byteOrWordType, isSigned));
}


const TypeDesc *
TypeManager::getPointerToVoid() const
{
    return getPointerTo(getVoidType());
}


// Can be called for a non-array, by passing zero for numArrayDimensions.
// Then this function just returns pointedTypeDesc.
//
const TypeDesc *
TypeManager::getArrayOf(const TypeDesc *pointedTypeDesc, size_t numArrayDimensions) const
{
    if (pointedTypeDesc == NULL)
        return NULL;

    if (numArrayDimensions == 0)
        return pointedTypeDesc;

    if (numArrayDimensions == 1)
    {
        for (vector<TypeDesc *>::const_iterator it = types.begin(); it != types.end(); ++it)
        {
            const TypeDesc *td = *it;
            assert(td && td->isValid());
            if (td->type == ARRAY_TYPE && td->pointedTypeDesc == pointedTypeDesc && td->numArrayElements == uint16_t(-1))
                return td;
        }

        types.push_back(new TypeDesc(ARRAY_TYPE, pointedTypeDesc, string(), false, false));
        return types.back();
    }

    return getArrayOf(getArrayOf(pointedTypeDesc, numArrayDimensions - 1), 1);
}


// getSizedArrayOf("int", {2, 3, 4}, 2) gives int[2][3][4].
// It recursively calls getSizedArrayOf("int", {2, 3, 4}, 1) to request int[2][3].
// This called getSizedArrayOf("int", {2, 3, 4}, 0) to get int[2].
// Then int[2][3] is created and returned.
// Then int[2][3][4] is created and returned.
//
const TypeDesc *
TypeManager::getSizedArrayOf(const TypeDesc *pointedTypeDesc, const std::vector<uint16_t> &arrayDimensions, size_t dimIndex) const
{
    //cerr << "# TypeManager::getSizedArrayOf([" << pointedTypeDesc->toString() << "], {" << join(", ", arrayDimensions) << "}, " << dimIndex << ")\n";
    assert(dimIndex < arrayDimensions.size());

    if (pointedTypeDesc == NULL)
        return NULL;

    if (dimIndex == 0)
    {
        for (vector<TypeDesc *>::const_iterator it = types.begin(); it != types.end(); ++it)
        {
            const TypeDesc *td = *it;
            assert(td && td->isValid());
            if (td->type == ARRAY_TYPE && td->pointedTypeDesc == pointedTypeDesc && td->numArrayElements == arrayDimensions[dimIndex])
                return td;
        }

        types.push_back(new TypeDesc(ARRAY_TYPE, pointedTypeDesc, string(), false, false, arrayDimensions[dimIndex]));
        return types.back();
    }

    const TypeDesc *subTypeDesc = getSizedArrayOf(pointedTypeDesc, arrayDimensions, dimIndex - 1);
    return getSizedArrayOf(subTypeDesc, arrayDimensions, dimIndex);
}


const TypeDesc *
TypeManager::getClassType(const std::string &className, bool isUnion, bool createIfAbsent) const
{
    for (vector<TypeDesc *>::const_iterator it = types.begin(); it != types.end(); ++it)
    {
        const TypeDesc *td = *it;
        assert(td && td->isValid());
        if (td->type == CLASS_TYPE && td->isUnion == isUnion && td->className == className)
            return td;
    }

    if (createIfAbsent)
    {
        if (getClassType(className, !isUnion, false) != NULL)
            errormsg("referring to %s as a %s, but it is a %s",
                        className.c_str(), isUnion ? "union" : "struct", !isUnion ? "union" : "struct");

        types.push_back(new TypeDesc(CLASS_TYPE, NULL, className, false, isUnion));
        return types.back();
    }

    return NULL;
}


const TypeDesc *TypeManager::getFunctionPointerType() const
{
    return getPointerToVoid();
}


// Ends by calling delete on 'declarator'.
//
bool
TypeManager::addTypeDef(const TypeDesc *declSpecTypeDef, Declarator *declarator)
{
    assert(declSpecTypeDef);
    assert(declarator);

    bool success = false;

    string id = declarator->getId();
    TypeDefMap::iterator it = typeDefs.find(id);
    if (it != typeDefs.end())  // if type name already used:
        errormsg("cannot redefine typedef %s", id.c_str());
    else
    {
        // Example: With "typedef int **PP;", declSpecTypeDef represents "int"
        // and declarator represents (2, "PP"), where 2 is the pointer level.
        // The next call assigns "int **" to specificTypeDesc.
        //
        const TypeDesc *specificTypeDesc = declarator->processPointerLevel(declSpecTypeDef);
        assert(specificTypeDesc);
        //cerr << "#   After processPointerLevel: " << specificTypeDesc->toString() << endl;

        vector<uint16_t> arrayDimensions;
        if (declarator->computeArraySize(arrayDimensions))  // arrayDimensions will be empty if non-array
        {
            if (arrayDimensions.size() > 0)
            {
                specificTypeDesc = getSizedArrayOf(specificTypeDesc, arrayDimensions, arrayDimensions.size() - 1);
                //cerr << "#   After getSizedArrayOf    : " << specificTypeDesc->toString() << endl;
            }

            typeDefs[id] = specificTypeDesc;
            success = true;
        }
    }

    delete declarator;

    return success;
}


const TypeDesc *
TypeManager::getTypeDef(const char *id) const
{
    TypeDefMap::const_iterator it = typeDefs.find(id);
    if (it != typeDefs.end())
        return it->second;
    return NULL;
}
