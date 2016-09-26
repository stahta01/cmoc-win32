
#include "_heap.h"

// Returns a pointer to end of heap, or nullptr for failure.

heap_t* heap_init(heap_t* heap, size_t size)
{
    if (size < HEAP_SIZE_MIN || size > HEAP_SIZE_MAX) {
        return nullptr;
    }
    heap = (int*)((int)heap - (*heap = sizeof(int) - size));
    heap[0] = 0;
    return heap;
}

