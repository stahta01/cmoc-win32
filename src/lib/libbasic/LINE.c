
#include <basic.h>
#include <stdlib.h>
#include <motorola.h>
#include <math.h>

void LINE(int x1, int y1, int x2, int y2, byte c)
{
    int x = x2 - x1, y = y2 - y1;
    if (_abs(x) > 100 || _abs(y) > 100) {
        x = (x1 + x2) / 2;
        y = (y1 + y2) / 2;
        LINE(x1, y1, x, y, c);
        LINE(x, y, x2, y2, c);
    } else {
        x = _basic.pclip.x1;
        y = _basic.pclip.x2;
        if (x1 < x) {
            if (x2 < x) {
                return;
            }
            y1 += (y2 - y1) * (x - x1) / (x2 - x1);
            x1 = x;
        } else {
            if (x1 > y) {
                if (x2 > y) {
                    return;
                }
                y1 += (y2 - y1) * (y - x1) / (x2 - x1);
                x1 = y;
            }
        }
        if (x2 < x) {
            if (x1 < x) {
                return;
            }
            y2 += (y2 - y1) * (x - x2)/(x2 - x1);
            x2 = x;
        } else {
            if (x2 > y) {
                if (x1 > y) {
                    return;
                }
                y2 += (y2 - y1) * (y - x2) / (x2 - x1);
                x2 = y;
            }
        }
        x = _basic.pclip.y1;
        y = _basic.pclip.y2;
        if (y1 < x) {
            if (y2 < x) {
                return;
            }
            x1 += (x2 - x1) * (x - y1) / (y2 - y1);
            y1 = x;
        } else {
            if (y1 > y) {
                if (y2 > y) {
                    return;
                }
                x1 += (x2 - x1) * (y - y1) / (y2 - y1);
                y1 = y;
            }
        }
        if (y2 < x) {
            if (y1 < x) {
                return;
            }
            x2 += (x2 - x1) * (x - y2) / (y2 - y1);
            y2 = x;
        } else {
            if (y2 > y) {
                if (y1 > y) {
                    return;
                }
                x2 += (x2 - x1) * (y - y2) / (y2 - y1);
                y2 = y;
            }
        }
        if (_pmode < 4)  {
            x1 >>= 1;
            x2 >>= 1;
            if (_pmode < 2) {
                y1 >>= 1;
                y2 >>= 1;
            }
        }

        x2 -= x1;
        y2 -= y1;
        int w = _abs(x2), h = _abs(y2), i = _max(w, h);
        if (i) {
            x1 = _i2f(x1);
            y1 = _i2f(y1);
            x2 = _i2f(x2) / i;
            y2 = _i2f(y2) / i;
            if (_pmode & 1) {
                while (i-- > 0) {
                    PSET2(_HIBYTE(x1), _HIBYTE(y1), c);
                    x1 += x2;
                    y1 += y2;
                }
            } else {
                while (i-- > 0) {
                    PSET2(_HIBYTE(x1), _HIBYTE(y1), c);
                    x1 += x2;
                    y1 += y2;
                }
            }
        }
    }
}































