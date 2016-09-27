
#include "_malloc.h"

void* realloc(void* memory, size_t size)
{
    return heap_realloc(__malloc_heap, memory, size);
}

