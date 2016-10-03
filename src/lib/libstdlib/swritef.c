
#include "_stdlib.h"

int swritef(char* dst, char* fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    int result = vswritef(dst, fmt, args);
    va_end();
    return result;
}

