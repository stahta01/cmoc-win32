
#include "_basic.h"

void MSET(int x, int y, byte c)
{
    _setcolor(c);
    _setpixel(x, y);
}

byte MPOINT(int x, int y)
{
    return (byte)_getpixel(x, y);
}




