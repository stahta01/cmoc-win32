
#include "_conio.h"

unsigned char textcolor(unsigned char color)
{
    unsigned char result = _forcol;
    _forcol = color;
    return result;
}

