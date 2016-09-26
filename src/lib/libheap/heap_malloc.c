
#include "_heap.h"

#pragma options --optimize=2

void* heap_malloc(heap_t* heap, size_t size)
{
    if (size) {
        size += sizeof(int);
        for (int bsize; bsize = *heap; heap = (int*)((int)heap + (bsize < 0 ? -bsize : bsize))) {
            if (bsize < 0) {
                bsize = 0;
                for (int* block = heap; *block < 0; block = (int*)((int)block - *block)) {
                    bsize += *block;
                }
                *heap = bsize;
            }
            if ((int)size <= (-bsize - sizeof(int))) {
                if ((int)size < -bsize) {
                    *(int*)((int)heap + size) = bsize + size;
                }
                *heap++ = size;
                return (void*)heap;
            }
        }
    }
    return nullptr;
}

