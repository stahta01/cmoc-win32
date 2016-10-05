
#include "_far.h"

far_char_t* far_strdup(far_char_t* dst, far_char_t* src)
{
    if (dst = (far_char_t*)far_malloc((far_void_t*)dst, far_strlen(src) + 1)) {
        far_strcpy(dst, src);
    }
    return dst;
}

