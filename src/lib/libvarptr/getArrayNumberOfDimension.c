
#include "_varptr.h"

// Returns the number of dimensions in an array found by findArrayVariable().
//
byte _getArrayNumberOfDimension(void* arrayStorage)
{
    return * (byte*) arrayStorage;
}

