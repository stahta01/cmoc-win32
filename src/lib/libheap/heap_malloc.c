
#include "_heap.h"

#pragma options --optimize=2

void* heap_malloc(heap_t* heap, int size)
{
    if (size) {
        size += sizeof(int);
        while (*heap) {
            int block_size = *heap;
            if (block_size < 0) {
                block_size = 0;
                for (int* block = heap; *block < 0; block = (int*)((int)block - *block)) {
                    block_size += *block;
                }
                *heap = block_size;
            }
            if (size <= (-block_size - sizeof(int))) {
                if (size < -block_size) {
                    *(int*)((int)heap + size) = block_size + size;
                }
                *heap++ = size;
                return (void*)heap;
            }
            heap = (int*)((int)heap + (block_size < 0 ? -block_size : block_size));
        }
    }
    return nullptr;
}

