
#include <basic.h>

void MSET(int x, int y, byte c)
{
    if (_pmode & 1) {
        MSET2(x, y, c);
    } else {
        MSET1(x, y, c);
    }
}

byte MPOINT(int x, int y)
{
    return _pmode & 1  ? MPOINT2(x, y) : MPOINT1(x, y);
}




