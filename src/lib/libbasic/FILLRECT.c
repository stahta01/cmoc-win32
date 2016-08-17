
#include <basic.h>

void FILLRECT(int x1, int y1, int x2, int y2, byte c)
{
    if (x1 <= x2 && y1 <= y2) {
        if ((x2 - x1) > (y2 - y1)) {
            for (; y1 <= y2; y1++) {
                LINE(x1, y1, x2, y1, c);
            }
        } else {
            for (; x1 <= x2; x1++) {
                LINE(x1, y1, x1, y2, c);
            }
        }
    }
}









