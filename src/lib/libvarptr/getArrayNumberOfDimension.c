
#include "_varptr.h"

// Returns the number of dimensions in an array found by findArrayVariable().
//
byte getArrayNumberOfDimension(void* arrayStorage)
{
    return * (byte*) arrayStorage;
}

