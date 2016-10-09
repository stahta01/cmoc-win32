
#include <basic.h>
#include <ctype.h>

#define VIDCHAR(X,Y) *(byte*)(1024+((word)(Y)<<5)+(word)(X))
#define VIDSEMI(X,Y) VIDCHAR(X>>1,Y>>1)

int main(void)
{
    int i;
    int cx = 0, cy = 0, cc = 128, jx = 1, jy = 1;
    int pen = 2;

    LOADM("CLOWN.PIC:1", 0);

    cc = VIDSEMI(cx,cy);

    for (;;) {
        int c = INKEY();
        if (isdigit(c)) {
            pen = c - '0';
        }
        if (c == 'L') {
            LOADM("JOYSTK.PIC", 0);
            cc = VIDSEMI(cx,cy);
        }
        if (c == 'S') {
            VIDSEMI(cx, cy) = (byte)cc;
            SAVEM("JOYSTK.PIC", 1024, 1024 + 511, 0);
        }
        jx = JOYSTK(0);
        jy = JOYSTK(1) >> 1;
        if (jx != cx || jy != cy) {
            VIDSEMI(cx, cy) = (byte)cc;
            cx = jx;
            cy = jy;
            cc = VIDSEMI(cx, cy);
            if (LPOINT(cx, cy)) {
                LSET(cx, cy, 0);
            } else {
                LSET(cx, cy, ((cc >> 4) & 7) + 1);
            }
        }
        if ((PEEK(65280) & 1) == 0) {
            LSET(cx, cy, pen);
            cc = VIDSEMI(cx,cy);
        }
    }
    return 0;
}

