
#include <basic.h>
#include <stdlib.h>
#include <motorola.h>

void _LINE(void)
{
    X2 -= X1;
    Y2 -= Y1;
    int w = _abs(X2), h = _abs(Y2), i = _max(w, h);
    if (i) {
        _HIBYTE(X1) = _LOBYTE(X1);
        _HIBYTE(Y1) = _LOBYTE(Y1);
        _HIBYTE(X2) = _LOBYTE(X2);
        _HIBYTE(Y2) = _LOBYTE(Y2);
        _LOBYTE(X1) = _LOBYTE(Y1) = _LOBYTE(X2) = _LOBYTE(Y2) = 127;
        X2 /= i;
        Y2 /= i;
        while (i-- >= 0) {
            X = _HIBYTE(X1);
            Y = _HIBYTE(Y1);
            _SET();
            X1 += X2;
            Y1 += Y2;
        }
    } else {
        X = X1;
        Y = Y1;
        _SET();
    }
}

void LINE(int x1, int y1, int x2, int y2, byte c)
{
    C = c;
    X1 = x1;
    Y1 = y1;
    X2 = x2;
    Y2 = y2;
    _LINE();
}











