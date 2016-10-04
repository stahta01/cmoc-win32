
#include "_malloc.h"

void* realloc(void* memory, size_t size)
{
    return heap_realloc(mheap(), memory, size);
}

