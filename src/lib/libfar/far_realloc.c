
#include "_far.h"

far_void_t* far_realloc(far_void_t* memory, size_t size)
{
    size_t oldsize = far_msize(memory);
    if (oldsize != size) {
        far_void_t newmem;
        if (far_malloc(&newmem, size)->data) {
            far_memcpy(&newmem, memory, oldsize < size ? oldsize : size);
        }
        far_free(memory);
        *memory = newmem;
    }
    return memory;
}

