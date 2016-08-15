
#include <basic.h>
#include <stdlib.h>
#include <fixpt.h>

void DRAWLINE(int x1, int y1, int x2, int y2, byte c)
{
    x2 -= x1;
    y2 -= y1;
    int x = _abs(x2), y = _abs(y2), i = _max(x, y);
    if (i) {
        int_hi(x1) = int_lo(x1);
        int_hi(y1) = int_lo(y1);
        int_hi(x2) = int_lo(x2);
        int_hi(y2) = int_lo(y2);
        int_lo(x1) = int_lo(y1) = int_lo(x2) = int_lo(y2) = 127;
        x2 /= i;
        y2 /= i;
        while (i-- >= 0) {
            SET(int_hi(x1), int_hi(y1), c);
            x1 += x2;
            y1 += y2;
        }
    } else {
        SET((byte)x1, (byte)y1, c);
    }
}









