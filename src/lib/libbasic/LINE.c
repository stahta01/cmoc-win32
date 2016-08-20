
#include <basic.h>
#include <stdlib.h>
#include <motorola.h>
#include <math.h>

void _LINE(void)
{
    if (LINECLIPPER()) {
        if (_pmode < 4)  {
            zX1 >>= 1;
            zX2 >>= 1;
            if (_pmode < 2) {
                zY1 >>= 1;
                zY2 >>= 1;
            }
        }

        zX2 -= zX1;
        zY2 -= zY1;
        int w = _abs(zX2), h = _abs(zY2), i = _max(w, h);
        if (i) {
            zX1 = _i2f(zX1);
            zY1 = _i2f(zY1);
            zX2 = _i2f(zX2) / i;
            zY2 = _i2f(zY2) / i;
            if (_pmode & 1) {
                while (i-- > 0) {
                    zX = _HIBYTE(zX1);
                    zY = _HIBYTE(zY1);
                    _PSET2();
                    zX1 += zX2;
                    zY1 += zY2;
                }
            } else {
                while (i-- > 0) {
                    zX = _HIBYTE(zX1);
                    zY = _HIBYTE(zY1);
                    _PSET1();
                    zX1 += zX2;
                    zY1 += zY2;
                }
            }
        }
    }
}

void LINE(int x1, int y1, int x2, int y2, byte c)
{
    int x = x2 - x1, y = y2 - y1;
    if (_abs(x) > 100 || _abs(y) > 100) {
        x = (x1 + x2) / 2;
        y = (y1 + y2) / 2;
        LINE(x1, y1, x, y, c);
        LINE(x, y, x2, y2, c);
    } else {
        C = c;
        zX1 = x1;
        zY1 = y1;
        zX2 = x2;
        zY2 = y2;
        _LINE();
    }
}





























