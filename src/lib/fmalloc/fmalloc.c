
#include "_fmalloc.h"

far_void_t* fmalloc(size_t size)
{
    far_void_t* memory = (far_void_t*)malloc(sizeof(far_void_t));
    if (memory && !far_malloc(memory, size)) {
        free(memory);
        memory = nullptr;
    }
    return memory;
}

