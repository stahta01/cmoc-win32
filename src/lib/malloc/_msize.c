
#include "_malloc.h"

size_t _msize(void* memory)
{
    return heap_msize(memory);
}

