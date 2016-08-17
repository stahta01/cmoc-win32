
#include <basic.h>
#include <fixpt.h>
#include <motorola.h>

void PARC(int x, int y, int w, int h, int s, int e, byte c)
{
    int x1 = fxsin((byte)s) * w, x2 = x1;
    int y1 = fxcos((byte)s) * h, y2 = y1;
    if (s < e) {
        for (; s < e; s += 4) {
            x2 = fxsin((byte)s) * w;
            y2 = fxcos((byte)s) * h;
            PLINE(_F2I(x1) + x, _F2I(y1) + y, _F2I(x2) + x, _F2I(y2) + y, c);
            x1 = x2;
            y1 = y2;
        }
    } else {
        for (; s > e; s -= 4) {
            x2 = fxsin((byte)s) * w;
            y2 = fxcos((byte)s) * h;
            PLINE(_F2I(x1) + x, _F2I(y1) + y, _F2I(x2) + x, _F2I(y2) + y, c);
            x1 = x2;
            y1 = y2;
        }
    }
    x2 = fxsin((byte)e) * w;
    y2 = fxcos((byte)e) * h;
    PLINE(_F2I(x1) + x, _F2I(y1) + y, _F2I(x2) + x, _F2I(y2) + y, c);
}

