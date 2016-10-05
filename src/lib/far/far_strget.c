
#include "_far.h"

void far_strget(char* dst, far_char_t* src)
{
    strcpy(dst, (char*)far_zoom((far_void_t*)src));
    far_zoom((far_void_t*)src);
}

