
#include "_stdio.h"

int printf(char* fmt, ...)
{
    char buf[BUFSIZ];
    int result = vsprintf(buf, fmt, (va_list)&fmt);
    fputs(buf, stdout);
    return result;
}

