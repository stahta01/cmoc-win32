
#include <basic.h>

// TODO: Not quite right, but it works.

void PAINT(int x, int y, byte c)
{
    int x1, x2, y1, y2, mx;
    byte undercoat = PPOINT(x, y);
    if (undercoat != c) {
        byte xx = _pmode & 1 ? 2 : 1;
        byte yy = _pmode < 2 ? 2 : 1;
        for (x1 = x; x1 >= _basic.pclip.x1; x1 -= xx) {
            if (PPOINT(x1, y) != undercoat) {
                break;
            }
        }
        for (x2 = x; x2 < _basic.pclip.x2; x2 += xx) {
            if (PPOINT(x2, y) != undercoat) {
                break;
            }
        }
        for (y1 = y; y1 >= _basic.pclip.y1; y1 -= yy) {
            if (PPOINT(x, y1) != undercoat) {
                break;
            }
        }
        for (y2 = y; y2 < _basic.pclip.y2; y2 += yy) {
            if (PPOINT(x, y2) != undercoat) {
                break;
            }
        }
        x1 += xx;
        y1 += yy;
        LINE(x, y1, x, y2, c);
        LINE(x1, y, x2, y, c);
        if (y > _basic.pclip.y1) {
            for (mx = x1; mx < x2; mx += xx) {
                if (PPOINT(mx, y - yy) == undercoat) {
                    PAINT(mx, y - yy, c);
                }
            }
        }
        if (y < _basic.pclip.y2 - yy) {
            for (mx = x1; mx < x2; mx += xx) {
                if (PPOINT(mx, y + yy) == undercoat) {
                    PAINT(mx, y + yy, c);
                }
            }
        }
    }
}

