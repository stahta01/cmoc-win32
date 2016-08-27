
#include "_conio.h"

unsigned char bgcolor(unsigned char color)
{
    unsigned char result = _bakcol;
    _bakcol = color;
    return result;
}

