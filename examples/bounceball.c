
#pragma target coco

#include <basic.h>
#include <fixpt.h>

int main(void)
{
    int x, xx = 3, y, yy = 3, i;
    byte xxx = 0, yyy = 0;

    CLS(0);

    x = 31 << 8;
    y = 16 << 8;

    for (;;) {
        x += xx;
        y += yy;
        if (int_hi(x) < 0 || int_hi(x) > 63) {
            xx = -xx;
            SOUND(100, 0);
        }
        if (int_hi(y) < 0 || int_hi(y) > 31) {
            yy = -yy;
            SOUND(200, 0);
        }
        if (int_hi(x) != xxx || int_hi(y) != yyy) {
            SET(xxx, yyy, 0);
            xxx = int_hi(x);
            yyy = int_hi(y);
            SET(xxx, yyy, 6);
        }
    }
    return 0;
}








