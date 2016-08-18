
#include <basic.h>
#include <stdlib.h>
#include <math.h>
#include <motorola.h>

void _SETLINE(void)
{
    X2 -= X1;
    Y2 -= Y1;
    int w = _abs(X2), h = _abs(Y2), i = _max(w, h);
    if (i) {
        X1 = _i2f(X1);
        Y1 = _i2f(Y1);
        X2 = _i2f(X2) / i;
        Y2 = _i2f(Y2) / i;
        while (i-- > 0) {
            X = _HIBYTE(X1);
            Y = _HIBYTE(Y1);
            _SET();
            X1 += X2;
            Y1 += Y2;
        }
    }
}

void SETLINE(int x1, int y1, int x2, int y2, byte c)
{
    C = c;
    X1 = x1;
    Y1 = y1;
    X2 = x2;
    Y2 = y2;
    _SETLINE();
}












