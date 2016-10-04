
#include "_malloc.h"

void* calloc(size_t count, size_t size)
{
    return heap_calloc(malloc_heap(nullptr), count, size);
}

