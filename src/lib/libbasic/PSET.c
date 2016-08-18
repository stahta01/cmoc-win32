
#include <basic.h>

void PSET(int x, int y, byte c)
{
    if (_pmode & 1) {
        PSET2(x, y, c);
    } else {
        PSET1(x, y, c);
    }
}

byte PPOINT(int x, int y)
{
    return _pmode & 1  ? PPOINT2(x, y) : PPOINT1(x, y);
}




