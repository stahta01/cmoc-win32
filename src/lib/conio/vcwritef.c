
#include "_conio.h"

int vcwritef(char* fmt, va_list args)
{
    char buf[MAX_INPUT];
    int result = vswritef(buf, fmt, args);
    cputs(buf);
    return result;
}

