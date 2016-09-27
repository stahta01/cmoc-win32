
#include "_malloc.h"

void* malloc(size_t size)
{
    return heap_malloc(__malloc_heap, size);
}

