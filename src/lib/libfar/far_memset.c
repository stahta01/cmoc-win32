
#include "_far.h"

far_void_t* far_memset(far_void_t* dst, int data, size_t size)
{
    memset(far_zoom(dst), data, size);
    far_zoom(dst);
    return dst;
}

