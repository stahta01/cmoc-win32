
#include "_heap.h"

// Note: For some strange reason, this code will not work on Vcc unless we use -O2 or -O0.
// The code works fine with XRoar, but I don't know about real hardware.
// To me, it looks like Vcc has a 6809 emulation issue, but I couldn't find it, and I've
// spent too long looking.

#pragma options --optimize=2

void* heap_malloc(heap_t* heap, int size)
{
    if (size) {
        int* block = heap + 1;
        size += sizeof(int);
        for (;;) {
            int mfree = *heap - (int)block;
            if (mfree <= 0) {
                return 0;
            }
            if (*block < 0) {
                int size = 0, *ptr = block;
                do {
                    size += *ptr;
                    ptr = (int*)((int)ptr - *ptr);
                } while (*ptr < 0);
                *block = size;
            } else if (*block == 0) {
                *block = -mfree;
            }
            if (size <= -*block) {
                break;
            }
            block = (int*)((int)block + (*block < 0 ? -*block : *block));
        }
        if (size != -*block) {
            *(int*)((int)block + size) = *block + size;
        }
        *block++ = size;
        return (void*)block;
    } else {
        return nullptr;
    }
}

