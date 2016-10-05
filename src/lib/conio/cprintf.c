
#include "_conio.h"

int cprintf(char* fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    int result = vcprintf(fmt, args);
    va_end();
    return result;
}

