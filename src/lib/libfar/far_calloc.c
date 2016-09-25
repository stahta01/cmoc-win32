
#include "_far.h"

far_void_t* far_calloc(far_void_t* dst, size_t count, size_t size)
{
    if (far_malloc(dst, size *= count)->data) {
        far_memset(dst, 0, size);
    }
    return dst;
}

