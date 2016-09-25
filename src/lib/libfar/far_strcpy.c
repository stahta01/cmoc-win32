
#include "_far.h"

far_char_t* far_strcpy(far_char_t* dst, far_char_t* src)
{
    return (far_char_t*)far_memcpy((far_void_t*)dst, (far_void_t*)src, far_strlen(src) + 1);
}

