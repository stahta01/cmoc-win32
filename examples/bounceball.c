
#pragma target coco

#include <basic.h>
#include <windef.h>

INT main(VOID)
{
    INT x, xx = 3, y, yy = 3, i;
    BYTE xxx = 0, yyy = 0;

    CLS(0);

    x = 31 << 8;
    y = 16 << 8;

    for (;;) {
        x += xx;
        y += yy;
        if (HIBYTE(x) < 0 || HIBYTE(x) > 63) {
            xx = -xx;
            SOUND(100, 0);
        }
        if (HIBYTE(y) < 0 || HIBYTE(y) > 31) {
            yy = -yy;
            SOUND(200, 0);
        }
        if (HIBYTE(x) != xxx || HIBYTE(y) != yyy) {
            SET(xxx, yyy, 0);
            xxx = HIBYTE(x);
            yyy = HIBYTE(y);
            SET(xxx, yyy, 6);
        }
    }
    return 0;
}








