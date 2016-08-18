
#include <basic.h>
#include <stdlib.h>
#include <motorola.h>
#include <fixpt.h>

void _PLINE_CLIP(void)
{
    if (_pmode & 1)  {
        X1 >>= 1;
        X2 >>= 1;
    }
    if (_pmode < 2) {
        Y1 >>= 1;
        Y2 >>= 1;
    }
    /*
    if ((X1 < _basic.pclip.x1 && X2 < _basic.pclip.x1) || (X1 > _basic.pclip.x2 && X2 > _basic.pclip.x2)
        || (Y1 < _basic.pclip.y1 && Y2 < _basic.pclip.y1) || (Y1 > _basic.pclip.y2
                && Y2 > _basic.pclip.y2)) {
        return;
    }
    CLIP(X1, Y1, X2 - X1, Y2 - Y1, _basic.pclip.x1, _basic.pclip.x2);
    if ((X1 < _basic.pclip.x1 && X2 < _basic.pclip.x1) || (X1 > _basic.pclip.x2 && X2 > _basic.pclip.x2)
        || (Y1 < _basic.pclip.y1 && Y2 < _basic.pclip.y1) || (Y1 > _basic.pclip.y2
                && Y2 > _basic.pclip.y2)) {
        return;
    }
    CLIP(X2, Y2, X2 - X1, Y2 - Y1, _basic.pclip.x1, _basic.pclip.x2);
    if ((X1 < _basic.pclip.x1 && X2 < _basic.pclip.x1) || (X1 > _basic.pclip.x2 && X2 > _basic.pclip.x2)
        || (Y1 < _basic.pclip.y1 && Y2 < _basic.pclip.y1) || (Y1 > _basic.pclip.y2
                && Y2 > _basic.pclip.y2)) {
        return;
    }
    CLIP(Y1, X1, Y2 - Y1, X2 - X1, _basic.pclip.y1, _basic.pclip.y2);
    if ((X1 < _basic.pclip.x1 && X2 < _basic.pclip.x1) || (X1 > _basic.pclip.x2 && X2 > _basic.pclip.x2)
        || (Y1 < _basic.pclip.y1 && Y2 < _basic.pclip.y1) || (Y1 > _basic.pclip.y2
                && Y2 > _basic.pclip.y2)) {
        return;
    }
    CLIP(Y2, X2, Y2 - Y1, X2 - X1, _basic.pclip.y1, _basic.pclip.y2);
    if ((X1 < _basic.pclip.x1 && X2 < _basic.pclip.x1) || (X1 > _basic.pclip.x2 && X2 > _basic.pclip.x2)
        || (Y1 < _basic.pclip.y1 && Y2 < _basic.pclip.y1) || (Y1 > _basic.pclip.y2
                && Y2 > _basic.pclip.y2)) {
        return;
    }
    */
}

void _PLINE(void)
{
    if (_pmode & 1)  {
        X1 >>= 1;
        X2 >>= 1;
    }
    if (_pmode < 2) {
        Y1 >>= 1;
        Y2 >>= 1;
    }

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

void PLINE(int x1, int y1, int x2, int y2, byte c)
{
    int x = x2 - x1, y = y2 - y1;
    if (_abs(x) > 100 || _abs(y) > 100) {
        x = (x1 + x2) / 2;
        y = (y1 + y2) / 2;
        PLINE(x1, y1, x, y, c);
        PLINE(x, y, x2, y2, c);
    } else {
        C = c;
        X1 = x1;
        Y1 = y1;
        X2 = x2;
        Y2 = y2;
        _PLINE();
    }
}



























