
#include <conio.h>

unsigned char bgcolor(unsigned char color)
{
    unsigned char result = _conio.bgcolor;
    _conio.bgcolor = color;
    return result;
}

