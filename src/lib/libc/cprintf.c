
#include <stdio.h>
#include <conio.h>

int cprintf(char* fmt, ...)
{
    int result = vsprintf(_stdbuf, fmt, (va_list)&fmt);
    cputs(_stdbuf);
    return result;
}

