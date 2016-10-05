
#include "_sscanf.h"

int sscanf(char* str, char* fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    int result = vsscanf(str, fmt, args);
    va_end();
    return result;
}

