
#include "_libc.h"

int sprintf(char* dst, char* fmt, ...)
{
    return vsprintf(dst, fmt, (va_list)&fmt);
}

