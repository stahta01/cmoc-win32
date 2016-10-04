
#include "_malloc.h"

void* calloc(size_t count, size_t size)
{
    return heap_calloc(mheap(), count, size);
}

