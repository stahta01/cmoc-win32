
#include "_far.h"

far_void_t* far_memcpy(far_void_t* dst, far_void_t* src, size_t size)
{
    for (size_t min; size; size -= min) {
        byte buf[256];
        min = size < sizeof(buf) ? size : sizeof(buf);
        memcpy(buf, far_zoom(src), min);
        far_zoom(src);
        memcpy(far_zoom(dst), buf, min);
        far_zoom(dst);
    }
    return dst;
}

