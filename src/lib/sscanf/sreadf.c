
#include "_sscanf.h"

int sreadf(char* str, char* fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    int result = vsreadf(str, fmt, args);
    va_end();
    return result;
}

