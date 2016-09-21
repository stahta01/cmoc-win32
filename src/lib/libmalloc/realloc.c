
#include "_malloc.h"

void* realloc(void* mem, size_t size)
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

