
#include "_far.h"

far_char_t* far_strnew(far_char_t* dst, char* src)
{
    if (dst = (far_char_t*)far_malloc((far_void_t*)dst, strlen(src) + 1)) {
        far_strput(dst, src);
    }
    return dst;
}

