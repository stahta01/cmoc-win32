
#include "_malloc.h"

void* realloc(void* memory, size_t newsize)
{
    size_t oldsize = _msize(memory);
    if (oldsize != newsize) {
        if (malloc_uses_gmalloc) {
            void* newmem = grealloc(memory, newsize);
            if (!newmem) {
                newmem = heap_malloc(mheap(), newsize);
                if (newmem) {
                    memcpy(newmem, memory, oldsize < newsize ? oldsize : newsize);
                    free(memory);
                }
            }
            memory = newmem;
        } else {
            memory = heap_realloc(mheap(), memory, newsize);
        }
    }
    return memory;
}

