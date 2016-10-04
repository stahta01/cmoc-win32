
#include "_malloc.h"

void* realloc(void* memory, size_t size)
{
    void* result = malloc_uses_gmalloc ? grealloc(memory, size) : (void*)nullptr;
    return result ? result : heap_realloc(mheap(), memory, size);
}

