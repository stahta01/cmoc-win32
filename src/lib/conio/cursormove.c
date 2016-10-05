
#include "_conio.h"

void cursormove(int vt52_char)
{
    int w, h;
    screensize(&w, &h);
    int x = wherex();
    int y = wherey();
    switch (vt52_char) {
    case VT52_CHR_HOME:
        gotoxy(0, 0);
        break;
    case VT52_CHR_UP:
        if (y > 0) {
            gotoy(y - 1);
        }
        break;
    case VT52_CHR_RIGHT:
        if (x != w - 1) {
            gotox(x + 1);
            break;
        }
        gotox(0);
    // fall through to chr down
    case VT52_CHR_DOWN:
        if (y != h - 1) {
            gotoy(y + 1);
        } else {
            scrup();
        }
        break;
    case VT52_CHR_LEFT:
        if (x > 0) {
            gotox(x - 1);
        } else if (y > 0) {
            gotoxy(w - 1, y - 1);
        }
        break;
    }
}

