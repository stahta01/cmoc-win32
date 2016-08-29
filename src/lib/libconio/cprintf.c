
#include "_conio.h"

int cprintf(char* fmt, ...)
{
    char s[BUFSIZ];
    int result = vsprintf(s, fmt, (va_list)&fmt);
    cputs(s);
    return result;
}

