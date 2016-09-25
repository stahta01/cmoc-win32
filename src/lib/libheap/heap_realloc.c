
#include "_heap.h"

void* heap_realloc(heap_t* heap, void* memory, int newsize)
{
    int oldsize = heap_msize(memory);
    if (oldsize != newsize) {
        void* newmem = heap_malloc(heap, newsize);
        if (newmem) {
            memcpy(newmem, memory, oldsize < newsize ? oldsize : newsize);
        }
        heap_free(memory);
        memory = newmem;
    }
    return memory;
}

