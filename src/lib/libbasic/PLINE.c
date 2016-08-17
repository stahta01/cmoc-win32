
#include <basic.h>
#include <stdlib.h>
#include <motorola.h>
#include <fixpt.h>

void __PLINE(void)
{
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
    X2 -= X1;
    Y2 -= Y1;
    int w = _abs(X2), h = _abs(Y2), i = _max(w, h);
    if (i) {
        X1 = _I2F(X1);
        Y1 = _I2F(Y1);
        X2 = _I2F(X2) / i;
        Y2 = _I2F(Y2) / i;
        while (i-- >= 0) {
            PSET(_HIBYTE(X1), _HIBYTE(Y1), _wcolor);
            X1 += X2;
            Y1 += Y2;
        }
    } else {
        PSET(X1, Y1, _wcolor);
    }
}

void PLINE(int _x1, int _y1, int _x2, int _y2, byte c)
{
    int x = _x2 - _x1;
    int y = _y2 - _y1;
    if (_abs(x) > 100 || _abs(y) > 100) {
        x = (_x1 + _x2) / 2;
        y = (_y1 + _y2) / 2;
        PLINE(_x1, _y1, x, y, c);
        PLINE(x, y, _x2, _y2, c);
    } else {
        _wcolor = c;
        X1 = _x1;
        Y1 = _y1;
        X2 = _x2;
        Y2 = _y2;
        __PLINE();
    }
}











