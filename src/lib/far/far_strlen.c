
#include "_far.h"

int far_strlen(far_char_t* str)
{
    int len = strlen((char*)far_zoom((far_void_t*)str));
    far_zoom((far_void_t*)str);
    return len;
}

