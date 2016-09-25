
#include "_heap.h"

// Note: For some strange reason, this code will not work on Vcc unless we use -O2 or -O0.
// The code works fine with XRoar, but I don't know about real hardware.
// To me, it looks like Vcc has a 6809 emulation issue, but I couldn't find it, and I've
// spent too long looking.

#pragma options --optimize=2

void* heap_malloc(heap_t* heap, int size)
{
    if (size) {
        size += sizeof(int);
        for (int last = *heap++; heap < last; heap = (int*)((int)heap + (*heap < 0 ? -*heap : *heap))) {
            int spot = *heap;
            if (spot < 0) {
                spot = 0;
                for (int* p = heap; p < last && *p < 0; spot += *p, p = (int*)((int)p - *p));
            } else if (!spot) {
                spot = (int)heap - last;
            }
            *heap = spot;
            if (size <= -spot - 2) {
                if (size < -spot) {
                    *(int*)((int)heap + size) = spot + size;
                }
                *heap++ = size;
                return (void*)heap;
            }
        }
    }
    return nullptr;
}

