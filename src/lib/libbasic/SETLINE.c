
#include <basic.h>
#include <stdlib.h>
#include <math.h>
#include <motorola.h>

void _SETLINE(void)
{
    zX2 -= zX1;
    zY2 -= zY1;
    int w = _abs(zX2), h = _abs(zY2), i = _max(w, h);
    if (i) {
        zX1 = _i2f(zX1);
        zY1 = _i2f(zY1);
        zX2 = _i2f(zX2) / i;
        zY2 = _i2f(zY2) / i;
        while (i-- > 0) {
            zX = _HIBYTE(zX1);
            zY = _HIBYTE(zY1);
            _SET();
            zX1 += zX2;
            zY1 += zY2;
        }
    }
}

void SETLINE(int x1, int y1, int x2, int y2, byte c)
{
    C = c;
    zX1 = x1;
    zY1 = y1;
    zX2 = x2;
    zY2 = y2;
    _SETLINE();
}












