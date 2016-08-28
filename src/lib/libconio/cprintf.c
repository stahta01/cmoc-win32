
#include "_conio.h"

int cprintf(char* fmt, ...)
{
    int result = vsprintf((char*)_linbuf + 1, fmt, (va_list)&fmt);
    cputs(_linbuf + 1);
    return result;
}

