
#include <basic.h>

void DRAWRECT(byte x1, byte y1, byte x2, byte y2, byte c)
{
    if (x1 <= x2 && y1 <= y2) {
        DRAWLINE(x1, y1, x2, y1, c);
        DRAWLINE(x2, y1, x2, y2, c);
        DRAWLINE(x2, y2, x1, y2, c);
        DRAWLINE(x1, y2, x1, y1, c);
    }
}



