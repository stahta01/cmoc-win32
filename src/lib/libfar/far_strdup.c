
#include "_far.h"

void far_strdup(far_char_t* dst, char* src)
{
    if (far_alloc((far_void_t*)dst, strlen(src) + 1)->ptr) {
        far_strput(dst, src);
    }
}

