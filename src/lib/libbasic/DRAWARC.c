
#include <basic.h>
#include <fixpt.h>
#include <windef.h>

void DRAWARC(byte x, byte y, int w, int h, int s, int e, byte c)
{
    int x1 = fxsin((byte)s) * w, x2 = x1;
    int y1 = fxcos((byte)s) * h, y2 = y1;
    if (s < e) {
        for (; s < e; s += 4) {
            x2 = fxsin((byte)s) * w;
            y2 = fxcos((byte)s) * h;
            DRAWLINE(HIBYTE(x1) + x, HIBYTE(y1) + y, HIBYTE(x2) + x, HIBYTE(y2) + y, c);
            x1 = x2;
            y1 = y2;
        }
    } else {
        for (; s > e; s -= 4) {
            x2 = fxsin((byte)s) * w;
            y2 = fxcos((byte)s) * h;
            DRAWLINE(HIBYTE(x1) + x, HIBYTE(y1) + y, HIBYTE(x2) + x, HIBYTE(y2) + y, c);
            x1 = x2;
            y1 = y2;
        }
    }
    x2 = fxsin((byte)e) * w;
    y2 = fxcos((byte)e) * h;
    DRAWLINE(HIBYTE(x1) + x, HIBYTE(y1) + y, HIBYTE(x2) + x, HIBYTE(y2) + y, c);
}

