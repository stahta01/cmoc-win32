
#include "_malloc.h"

void* malloc(size_t size)
{
    return heman_alloc(heap_memory, size);
}

