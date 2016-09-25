
#include "_heap.h"

#pragma options --optimize=2

void* heap_malloc(heap_t* heap, int size)
{
    if (size) {
        size += sizeof(int);
        for (int len, last = *heap++; heap < last; heap = (int*)((int)heap + (len < 0 ? -len : len))) {
            if ((len = *heap) < 0) {
                len = 0;
                for (int* p = heap; p < last && *p < 0; len += *p, p = (int*)((int)p - *p));
            } else if (!len) {
                len = (int)heap - last;
            }
            *heap = len;
            if (size <= -len - 2) {
                if (size < -len) {
                    *(int*)((int)heap + size) = len + size;
                }
                *heap++ = size;
                return (void*)heap;
            }
        }
    }
    return nullptr;
}

