
#include "_stdio.h"

int printf(char* fmt, ...)
{
    char buf[MAX_INPUT];
    va_list args;
    va_start(args, fmt);
    int result = vsprintf(buf, fmt, args);
    va_end();
    fputs(buf, stdout);
    return result;
}

