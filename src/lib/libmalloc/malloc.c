
#include "_malloc.h"

void* malloc(size_t size)
{
    if (!__malloc_heap) {
        __malloc_heap = (heap_t*)program_end;
        heap_init(__malloc_heap, 0x7c00 - (int)__malloc_heap);
    }
    return heap_malloc(__malloc_heap, size);
}

