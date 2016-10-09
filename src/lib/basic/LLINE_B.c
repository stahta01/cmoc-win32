
#include <basic.h>

void LLINE_B(int x1, int y1, int x2, int y2, int c)
{
    if (x1 < x2 && y1 < y2) {
        x2--;
        y2--;
        LLINE(x1, y1, x2, y1, c);
        LLINE(x2, y1, x2, y2, c);
        LLINE(x2, y2, x1, y2, c);
        LLINE(x1, y2, x1, y1, c);
    }
}

