
#include <conio.h>

unsigned char revers(unsigned char onoff)
{
    unsigned char result = _conio.revers;
    _conio.revers = onoff;
    return result;
}
