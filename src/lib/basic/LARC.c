
#include "_basic.h"

void LARC(int x, int y, int w, int h, int s, int e, int c)
{
    int x1 = sin6(s) * w, x2 = x1;
    int y1 = cos6(s) * h, y2 = y1;
    if (s < e) {
        for (; s < e; s += 8) {
            x2 = sin6(s) * w;
            y2 = cos6(s) * h;
            LLINE(f2i6(x1) + x, f2i6(y1) + y, f2i6(x2) + x, f2i6(y2) + y, c);
            x1 = x2;
            y1 = y2;
        }
    } else {
        for (; s > e; s -= 8) {
            x2 = sin6(s) * w;
            y2 = cos6(s) * h;
            LLINE(f2i6(x1) + x, f2i6(y1) + y, f2i6(x2) + x, f2i6(y2) + y, c);
            x1 = x2;
            y1 = y2;
        }
    }
    x2 = sin6(e) * w;
    y2 = cos6(e) * h;
    LLINE(f2i6(x1) + x, f2i6(y1) + y, f2i6(x2) + x, f2i6(y2) + y, c);
}

