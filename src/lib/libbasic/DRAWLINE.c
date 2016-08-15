
#include <basic.h>
#include <stdlib.h>
#include <windef.h>

VOID DRAWLINE(INT x1, INT y1, INT x2, INT y2, BYTE c)
{
    x2 -= x1;
    y2 -= y1;
    INT x = _abs(x2), y = _abs(y2), i = _max(x, y);
    if (i) {
        HIBYTE(x1) = LOBYTE(x1);
        HIBYTE(y1) = LOBYTE(y1);
        HIBYTE(x2) = LOBYTE(x2);
        HIBYTE(y2) = LOBYTE(y2);
        LOBYTE(x1) = LOBYTE(y1) = LOBYTE(x2) = LOBYTE(y2) = 127;
        x2 /= i;
        y2 /= i;
        while (i-- >= 0) {
            SET(HIBYTE(x1), HIBYTE(y1), c);
            x1 += x2;
            y1 += y2;
        }
    } else {
        SET((BYTE)x1, (BYTE)y1, c);
    }
}









