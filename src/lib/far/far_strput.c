
#include "_far.h"

void far_strput(far_char_t* dst, char* src)
{
    strcpy((char*)far_zoom((far_void_t*)dst), src);
    far_zoom((far_void_t*)dst);
}

