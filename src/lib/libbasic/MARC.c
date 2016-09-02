
#include <basic.h>
#include <fixpt.h>
#include <math.h>

void MARC(int x, int y, int w, int h, int s, int e, byte c)
{
    w <<= 1;
    h <<= 1;
    int x1 = fxsin((char)s) * w, x2 = x1;
    int y1 = fxcos((char)s) * h, y2 = y1;
    if (s < e) {
        for (; s < e; s += 8) {
            x2 = fxsin((char)s) * w;
            y2 = fxcos((char)s) * h;
            MLINE(_f2i(x1) + x, _f2i(y1) + y, _f2i(x2) + x, _f2i(y2) + y, c);
            x1 = x2;
            y1 = y2;
        }
    } else {
        for (; s > e; s -= 8) {
            x2 = fxsin((char)s) * w;
            y2 = fxcos((char)s) * h;
            MLINE(_f2i(x1) + x, _f2i(y1) + y, _f2i(x2) + x, _f2i(y2) + y, c);
            x1 = x2;
            y1 = y2;
        }
    }
    x2 = fxsin((char)e) * w;
    y2 = fxcos((char)e) * h;
    MLINE(_f2i(x1) + x, _f2i(y1) + y, _f2i(x2) + x, _f2i(y2) + y, c);
}

