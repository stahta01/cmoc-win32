
#include "_malloc.h"

void* malloc(size_t size)
{
    void* result = malloc_uses_gmalloc ? gmalloc(size) : (void*)nullptr;
    return result? result : heap_malloc(mheap(), size);
}

