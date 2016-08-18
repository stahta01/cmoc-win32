
#include <basic.h>

void SETBOX(int x1, int y1, int x2, int y2, byte c, bool fill)
{
    if (x1 <= x2 && y1 <= y2) {
        if (fill) {
            if ((x2 - x1) > (y2 - y1)) {
                for (; y1 <= y2; y1++) {
                    SETLINE(x1, y1, x2, y1, c);
                }
            } else {
                for (; x1 <= x2; x1++) {
                    SETLINE(x1, y1, x1, y2, c);
                }
            }
        } else {
            SETLINE(x1, y1, x2, y1, c);
            SETLINE(x2, y1, x2, y2, c);
            SETLINE(x2, y2, x1, y2, c);
            SETLINE(x1, y2, x1, y1, c);
        }
    }
}





