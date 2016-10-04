
#include "_heap.h"

void* heap_calloc(heap_t* heap, size_t count, size_t size)
{
    void* result = heap_malloc(heap, size *= count);
    return result ? memset(result, 0, size) : (void*)nullptr;
}

