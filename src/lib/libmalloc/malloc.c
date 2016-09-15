
#include "_malloc.h"

void* malloc(int size)
{
    if (size) {
        int* block = heap_memory;
        size += sizeof(int);
        for (;;) {
            int mfree = 32768 - (int)block;
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
        return 0;
    }
}

