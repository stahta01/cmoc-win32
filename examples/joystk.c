
#pragma target coco

#include <basic.h>
#include <ctype.h>

#define VIDCHAR(X,Y) *(byte*)(1024+(unsigned)(Y)*32+(unsigned)(X))
#define VIDSEMI(X,Y) VIDCHAR(X>>1,Y>>1)

int main(void)
{
    int i;
    byte cx = 0, cy = 0, cc = 128, jx = 1, jy = 1, pen = 2;

    for (i = 0; i < 32; i++)
    {
        LINE(0, i, 64, i, 1);
    }

    cc = VIDSEMI(cx,cy);

    for (;;) {
        char c = INKEY();
        if (isdigit(c)) {
            pen = c - '0';
        }
        jx = JOYSTK(0);
        jy = JOYSTK(1) >> 1;
        if (jx != cx || jy != cy) {
            VIDSEMI(cx, cy) = cc;
            cx = jx;
            cy = jy;
            cc = VIDSEMI(cx, cy);
            if (POINT(cx, cy)) {
                SET(cx, cy, 0);
            } else {
                SET(cx, cy, ((cc >> 4) & 7) + 1);
            }
        }
        if ((PEEK(65280) & 1) == 0) {
            SET(cx, cy, pen);
            cc = VIDSEMI(cx,cy);
        }
    }
    return 0;
}










