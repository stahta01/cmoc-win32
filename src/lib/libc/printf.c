
#include <stdio.h>

int printf(char* fmt, ...)
{
    char s[BUFSIZ];
    int result = vsprintf(s, fmt, (va_list)&fmt);
    fputs(s, stdout);
    return result;
}

