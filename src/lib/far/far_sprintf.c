
#include "_far.h"

int far_sprintf(far_char_t* dst, char* fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    int result = vsprintf((char*)far_zoom((far_void_t*)dst), fmt, args);
    far_zoom((far_void_t*)dst);
    va_end();
    return result;
}

