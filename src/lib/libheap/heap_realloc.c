
#include "_heap.h"

void* heap_realloc(heap_t* heap, void* memory, size_t newsize)
{
    size_t oldsize = heap_msize(memory);
    if (oldsize != newsize) {
        if (oldsize > 0) {
            ((heap_t*)memory)[-1] = -((heap_t*)memory)[-1];
            void* newmem = heap_malloc(((heap_t*)memory) - 1, newsize);
            if (newmem == memory) {
                return newmem;
            }
            heap_free(newmem);
            ((heap_t*)memory)[-1] = -((heap_t*)memory)[-1];
        }
        void* newmem = heap_malloc(heap, newsize);
        if (newmem) {
            memcpy(newmem, memory, oldsize < newsize ? oldsize : newsize);
            heap_free(memory);
        }
        memory = newmem;
    }
    return memory;
}

