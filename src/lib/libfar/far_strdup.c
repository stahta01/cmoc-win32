
#include "_far.h"

far_char_t* far_strdup(far_char_t* dst, far_char_t* src)
{
    return far_strcpy((far_char_t*)far_alloc((far_void_t*)dst, far_strlen(src) + 1), src);
}

