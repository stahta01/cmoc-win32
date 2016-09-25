
#include "_heman.h"

void* heman_realloc(int* heap, void* memory, int newsize)
{
    int oldsize = heman_size(memory);
    if (oldsize != newsize) {
        void* newmem = heman_alloc(heap, newsize);
        if (newmem) {
            memcpy(newmem, memory, oldsize < newsize ? oldsize : newsize);
        }
        heman_free(memory);
        memory = newmem;
    }
    return memory;
}

