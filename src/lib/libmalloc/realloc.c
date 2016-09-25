
#include "_malloc.h"

void* realloc(void* memory, size_t size)
{
    return heman_realloc(heap_memory, memory, size);
}

