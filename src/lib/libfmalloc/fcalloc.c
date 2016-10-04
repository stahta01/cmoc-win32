
#include "_fmalloc.h"

far_void_t* fcalloc(size_t count, size_t size)
{
    far_void_t* memory = (far_void_t*)malloc(sizeof(far_void_t));
    if (memory && !far_calloc(memory, count, size)) {
        free(memory);
        memory = nullptr;
    }
    return memory;
}

