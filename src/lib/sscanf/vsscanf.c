
#include "_sscanf.h"

int vsscanf(char* str, char* fmt, va_list args)
{
    return vsreadf(str, fmt, args);
}

