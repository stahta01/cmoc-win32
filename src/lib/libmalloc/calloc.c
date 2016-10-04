
#include "_malloc.h"

void* calloc(size_t count, size_t size)
{
    void* result = malloc_uses_gmalloc ? gcalloc(count, size) : (void*)nullptr;
    return result ? result : heap_calloc(mheap(), count, size);
}

