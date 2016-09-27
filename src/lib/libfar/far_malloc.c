
#include "_far.h"

far_void_t* far_malloc(far_void_t* dst, size_t size)
{
    if (dst->hank = hank_malloc(&dst->data, size)) {
        dst->bank = dst->hank->bank;
        return dst;
    }
    return nullptr;
}

