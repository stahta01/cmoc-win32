
#include <basic.h>
#include <stdlib.h>
#include <math.h>
#include <motorola.h>

void SETLINE(int x1, int y1, int x2, int y2, byte c)
{
    x2 -= x1;
    y2 -= y1;
    int w = _abs(x2), h = _abs(y2), i = _max(w, h);
    if (i) {
        x1 = _i2f(x1);
        y1 = _i2f(y1);
        x2 = _i2f(x2) / i;
        y2 = _i2f(y2) / i;
        while (i-- > 0) {
            SET(_HIBYTE(x1), _HIBYTE(y1), c);
            x1 += x2;
            y1 += y2;
        }
    }
}












