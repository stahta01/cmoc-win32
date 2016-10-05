
#include "_far.h"

void far_memget(void* dst, far_void_t* src, size_t size)
{
    memcpy(dst, far_zoom(src), size);
    far_zoom(src);
}

