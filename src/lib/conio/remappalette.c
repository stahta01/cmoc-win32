
#include "_conio.h"

void remappalette(int pen, int color)
{
    _paletreg[pen] = (byte)color;
}

