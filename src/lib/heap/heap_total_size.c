
#include "_heap.h"

size_t heap_total_size(heap_t* heap)
{
    int bsize, size = sizeof(int);              // end of heap marker counted as used.
    while (bsize = *heap) {
        if (bsize < 0) {
            size -= bsize;
            heap = (heap_t*)((word)heap - bsize);
        } else {
            size += bsize;
            heap = (heap_t*)((word)heap + bsize);
        }
    }
    return size;
}

