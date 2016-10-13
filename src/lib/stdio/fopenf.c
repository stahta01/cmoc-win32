
#include "_stdio.h"

FILE* fopenf(char* fmt, char* mode, ...)
{
    char buf[MAX_INPUT];
    va_list args;
    va_start(args, mode);
    vswritef(buf, fmt, args);
    va_end();
    return fopen(buf, mode);
}

