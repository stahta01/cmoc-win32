
#include <basic.h>

void FILLRECT(byte x1, byte y1, byte x2, byte y2, byte c)
{
    x2--;
    if (x1 < x2) {
        for (; y1 < y2; y1++) {
            DRAWLINE(x1, y1, x2, y1, c);
        }
    }
}





