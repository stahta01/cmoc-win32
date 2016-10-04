
#include "_sprintf.h"

int sprintf(char* dst, char* fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    int result = vsprintf(dst, fmt, args);
    va_end();
    return result;
}

