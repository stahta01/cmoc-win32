
#include "_conio.h"

void remapallpalette(byte* palette)
{
    memcpy(_PALETREG, palette, 16);
}

