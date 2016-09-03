
#include "_varptr.h"

// Returns the address of an element of an array found by findArrayVariable().
//
// Example: To get Basic array element A(3,5,7), do this:
//          void *a = findArrayVariable("A", FALSE);
//          if (a) {
//              word indices[] = { 3, 5, 7 };
//              void *elementStorage = getArrayElement(a, indices);
//          }
//
// Based on Color Basic routines at $B404 and $B4A0.
//
void* getArrayElement(void* arrayStorage, word indexArray[])
{
    byte numDims = * (byte*) arrayStorage;
    byte* dimArrayEnd = (byte*) arrayStorage + 1 + (word) numDims * 2;
    word* lastDim = (word*)(dimArrayEnd - 2);
    word elementOffset = 0;                 // in elements, not in bytes
    byte indexIndex = 0;
    word factor = 1;
    do {
        elementOffset += indexArray[indexIndex] * factor;
        factor *= lastDim[- indexIndex];
    } while (++indexIndex < numDims);

    return (void*)(dimArrayEnd + elementOffset * 5);
}

