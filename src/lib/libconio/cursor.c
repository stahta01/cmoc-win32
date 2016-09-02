
#include "_conio.h"

unsigned char cursor(unsigned char onoff)
{
    unsigned char result = _conio.cursor;
    _conio.cursor = onoff;
    return result;
}

