
#include <basic.h>

void FILLRECT(byte x1, byte y1, byte x2, byte y2, byte c)
{
    if (x1 <= x2 && y1 <= y2) {
        if ((x2 - x1) > (y2 - y1)) {
            for (; y1 <= y2; y1++) {
                DRAWLINE(x1, y1, x2, y1, c);
            }
        } else {
            for (; x1 <= x2; x1++) {
                DRAWLINE(x1, y1, x1, y2, c);
            }
        }
    }
}









