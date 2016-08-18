
#include <basic.h>

void SETRECT(int x1, int y1, int x2, int y2, byte c)
{
    if (x1 <= x2 && y1 <= y2) {
        SETLINE(x1, y1, x2, y1, c);
        SETLINE(x2, y1, x2, y2, c);
        SETLINE(x2, y2, x1, y2, c);
        SETLINE(x1, y2, x1, y1, c);
    }
}



