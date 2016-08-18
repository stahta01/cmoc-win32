
#include <basic.h>
#include <stdlib.h>
#include <motorola.h>
#include <math.h>

void _LINE(void)
{
    if (LINECLIPPER()) {
        if (_pmode < 4)  {
            X1 >>= 1;
            X2 >>= 1;
            if (_pmode < 2) {
                Y1 >>= 1;
                Y2 >>= 1;
            }
        }

        X2 -= X1;
        Y2 -= Y1;
        int w = _abs(X2), h = _abs(Y2), i = _max(w, h);
        if (i) {
            X1 = _i2f(X1);
            Y1 = _i2f(Y1);
            X2 = _i2f(X2) / i;
            Y2 = _i2f(Y2) / i;
            if (_pmode & 1) {
                while (i-- > 0) {
                    X = _HIBYTE(X1);
                    Y = _HIBYTE(Y1);
                    _PSET2();
                    X1 += X2;
                    Y1 += Y2;
                }
            } else {
                while (i-- > 0) {
                    X = _HIBYTE(X1);
                    Y = _HIBYTE(Y1);
                    _PSET1();
                    X1 += X2;
                    Y1 += Y2;
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
        X1 = x1;
        Y1 = y1;
        X2 = x2;
        Y2 = y2;
        _LINE();
    }
}





























