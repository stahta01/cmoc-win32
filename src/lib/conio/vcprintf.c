
#include "_conio.h"

int vcprintf(char* fmt, va_list args)
{
    char buf[MAX_INPUT];
    int result = vsprintf(buf, fmt, args);
    cputs(buf);
    return result;
}

