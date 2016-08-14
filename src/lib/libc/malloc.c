
#include <stdlib.h>
#include <string.h>

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


void free(void* m)
{
    if (m && ((int*)m)[-1] > 0) {
        ((int*)m)[-1] = -((int*)m)[-1];
    }
}

void* calloc(int n, int s)
{
    void* m = malloc(n *= s);
    return m ? memset(m, 0, n) : (void*)0;
}

void* realloc(void* mem, int size)
{
    if (_msize(mem) != size) {
        void* tmp = malloc(size);
        if (tmp) {
            memcpy(tmp, mem, _msize(mem) < size ? _msize(mem) : size);
        }
        free(mem);
        mem = tmp;
    }
    return mem;
}

int _msize(void* m)
{
    return m ? ((int*)m)[-1] - sizeof(int) : 0;
}

