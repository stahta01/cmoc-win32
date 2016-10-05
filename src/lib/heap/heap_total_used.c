
#include "_heap.h"

size_t heap_total_used(heap_t* heap)
{
    int bsize, size = sizeof(int);              // end of heap marker counted as used.
    while (bsize = *heap) {
        if (bsize < 0) {
            heap = (heap_t*)((word)heap - bsize);
        } else {
            size += bsize;
            heap = (heap_t*)((word)heap + bsize);
        }
    }
    return size;
}

