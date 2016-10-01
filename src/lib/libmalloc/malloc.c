
#include "_malloc.h"

void* malloc(size_t size)
{
    return heap_malloc(malloc_heap(nullptr), size);
}

