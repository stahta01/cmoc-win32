
#include "_conio.h"

int textcolor(int color)
{
    int result = _forcol;
    _forcol = (byte)color;
    return result;
}

