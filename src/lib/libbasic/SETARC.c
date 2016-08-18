
#include <basic.h>
#include <fixpt.h>
#include <math.h>

void SETARC(int x, int y, int w, int h, int s, int e, byte c, bool fill)
{
    int x1 = fxsin(s) * w, x2 = x1;
    int y1 = fxcos(s) * h, y2 = y1;
    if (s < e) {
        for (; s < e; s += 4) {
            x2 = fxsin(s) * w;
            y2 = fxcos(s) * h;
            SETLINE(_f2i(x1) + x, _f2i(y1) + y, _f2i(x2) + x, _f2i(y2) + y, c);
            x1 = x2;
            y1 = y2;
        }
    } else {
        for (; s > e; s -= 4) {
            x2 = fxsin(s) * w;
            y2 = fxcos(s) * h;
            SETLINE(_f2i(x1) + x, _f2i(y1) + y, _f2i(x2) + x, _f2i(y2) + y, c);
            x1 = x2;
            y1 = y2;
        }
    }
    x2 = fxsin(e) * w;
    y2 = fxcos(e) * h;
    SETLINE(_f2i(x1) + x, _f2i(y1) + y, _f2i(x2) + x, _f2i(y2) + y, c);
}

