
#include <stdio.h>

int printf(char* fmt, ...)
{
    int result = vsprintf(_stdbuf, fmt, (va_list)&fmt);
    fputs(_stdbuf, stdout);
    return result;
}

