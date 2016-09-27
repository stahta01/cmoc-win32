
#include "_malloc.h"

heap_t* malloc_heap(heap_t* heap)
{
    heap_t* result = __malloc_heap;
    if (heap) {
        __malloc_heap = heap;
    }
    return result;
}

