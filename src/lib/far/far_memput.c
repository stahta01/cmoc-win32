
#include "_far.h"

void far_memput(far_void_t* dst, void* src, size_t size)
{
    memcpy(far_zoom(dst), src, size);
    far_zoom(dst);
}

