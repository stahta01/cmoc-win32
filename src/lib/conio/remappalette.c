
#include "_conio.h"

void remappalette(int pen, int color)
{
    _paletreg[pen & 15] = (byte)color;
}

