
#include "_far.h"

far_void_t* far_malloc_put(far_void_t* dst, void* src, size_t size)
{
    if (dst = far_malloc(dst, size)) {
        far_memput(dst, src, size);
    }
    return dst;
}

