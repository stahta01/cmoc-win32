
#include "_conio.h"

int cprintfxy(int x, int y, char* fmt, ...)
{
    gotoxy(x, y);
    va_list args;
    va_start(args, fmt);
    int result = vcprintf(fmt, args);
    va_end();
    return result;
}

