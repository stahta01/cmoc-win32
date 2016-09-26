
#include "_heap.h"

heap_t* heap_init(heap_t* heap, size_t size)
{
    if (size < HEAP_SIZE_MIN || size > HEAP_SIZE_MAX) {
        return nullptr;
    }
    *heap = sizeof(int) - size;
    *(int*)((int)heap - *heap) = 0;
    return heap;
}

