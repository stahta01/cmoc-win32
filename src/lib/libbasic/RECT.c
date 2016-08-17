
#include <basic.h>

void RECT(int x1, int y1, int x2, int y2, byte c)
{
    if (x1 <= x2 && y1 <= y2) {
        LINE(x1, y1, x2, y1, c);
        LINE(x2, y1, x2, y2, c);
        LINE(x2, y2, x1, y2, c);
        LINE(x1, y2, x1, y1, c);
    }
}



