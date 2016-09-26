
#include "_heap.h"

#pragma options --optimize=2

void* heap_malloc(heap_t* heap, size_t size)
{
    if (size) {
        size += sizeof(int);
        for (int bsize; bsize = *heap; heap = (heap_t*)((word)heap + (bsize < 0 ? -bsize : bsize))) {
            if (bsize < 0) {
                bsize = 0;
                heap_block_t* block = heap;
                do {
                    bsize += *block;
                    block = (heap_block_t*)((word)block - *block);
                } while (*block < 0);
                *heap = bsize;
            }
            if ((int)size <= (-bsize - sizeof(int))) {
                *(int*)((int)heap + size) = bsize + size;
                goto success;
            }
            if (size == -bsize) {
                goto success;
            }
        }
    }
    return nullptr;
success:
    *heap++ = size;
    return (void*)heap;
}

