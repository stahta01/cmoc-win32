#include "_conio.h"

int cwritef(char* fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    int result = vcwritef(fmt, args);
    va_end();
    return result;
}

