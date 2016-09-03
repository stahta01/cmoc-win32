
#include "_varptr.h"

// Returns size of each dimension of an array found by findArrayVariable().
// The number of dimensions should be obtained from getArrayNumberOfDimension().
//
void getArrayDimensions(void* arrayStorage, word dimArray[])
{
    byte numDims = * (byte*) arrayStorage;
    memcpy(dimArray, ((byte*) arrayStorage) + 1, (word) numDims * 2);
}

