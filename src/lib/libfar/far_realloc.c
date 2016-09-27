
#include "_far.h"

far_void_t* far_realloc(far_void_t* dst, size_t size)
{
    size_t oldsize = far_msize(dst);
    if (oldsize != size) {
        far_void_t newmem;
        if (far_malloc(&newmem, size)) {
            far_memcpy(&newmem, dst, oldsize < size ? oldsize : size);
            far_free(dst);
            *dst = newmem;
        } else {
            return nullptr;
        }
    }
    return dst;
}

