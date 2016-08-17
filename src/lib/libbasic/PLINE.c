
#include <basic.h>
#include <stdlib.h>
#include <motorola.h>

void PLINE(int x1, int y1, int x2, int y2, int c)
{
    x2 -= x1;
    y2 -= y1;
    int x = _abs(x2), y = _abs(y2), i = _max(x, y);
    if (i) {
        _HIBYTE(x1) = _LOBYTE(x1);
        _HIBYTE(y1) = _LOBYTE(y1);
        _HIBYTE(x2) = _LOBYTE(x2);
        _HIBYTE(y2) = _LOBYTE(y2);
        _LOBYTE(x1) = _LOBYTE(y1) = _LOBYTE(x2) = _LOBYTE(y2) = 127;
        x2 /= i;
        y2 /= i;
        while (i-- >= 0) {
            PSET(_HIBYTE(x1), _HIBYTE(y1), c);
            x1 += x2;
            y1 += y2;
        }
    } else {
        PSET(x1, y1, c);
    }
}


