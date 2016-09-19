
#include "_conio.h"

int cprintf(char* fmt, ...)
{
    char buf[BUFSIZ];
    va_list args;
    va_start(args, fmt);
    int result = vsprintf(buf, fmt, args);
    va_end();
    cputs(buf);
    return result;
}

