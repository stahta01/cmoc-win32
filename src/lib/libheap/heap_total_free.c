
#include "_heap.h"

size_t heap_total_free(heap_t* heap)
{
    int bsize, size = 0;
    while (bsize = *heap) {
        if (bsize < 0) {
            size -= bsize;
            heap = (heap_t*)((word)heap - bsize);
        } else {
            heap = (heap_t*)((word)heap + bsize);
        }
    }
    return size;
}

