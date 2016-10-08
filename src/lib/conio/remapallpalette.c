
#include "_conio.h"

int remapallpalette(byte* palette)
{
    memcpy(_PALETREG, palette, 16);
    return 0;
}

