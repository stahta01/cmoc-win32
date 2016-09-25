
#include "_heap.h"

void heap_init(heap_t* heap, int size)
{
    heap[0] = (byte*)heap + size - sizeof(heap_t);
    heap[1] = 0;
}

