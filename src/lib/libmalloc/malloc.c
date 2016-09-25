
#include "_malloc.h"

void* malloc(size_t size)
{
    return heap_malloc(heap_memory, size);
}

