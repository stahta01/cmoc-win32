
#include "_conio.h"

int palettecolor(int r, int g, int b)
{
    return
        ((r & 2) << 4) | ((r & 1) << 2) |
        ((g & 2) << 3) | ((g & 1) << 1) |
        ((b & 2) << 2) | ((b & 1));
}

