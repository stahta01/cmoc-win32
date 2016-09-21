
#include "_malloc.h"

void* malloc(int size)
{
    return heman_alloc(heap_memory, size);
}

