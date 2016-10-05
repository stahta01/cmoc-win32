
#include "_conio.h"

void cursormove(int vt52_char)
{
    point_t p;
    wherexy(&p);
    int w, h;
    screensize(&w, &h);
    switch (vt52_char) {
    case VT52_CHR_HOME:
        gotoxy(0, 0);
        break;
    case VT52_CHR_UP:
        if (p.y > 0) {
            gotoxy(p.x, p.y - 1);
        }
        break;
    case VT52_CHR_RIGHT:
        if (p.x != w - 1) {
            gotoxy(p.x + 1, p.y);
            break;
        }
        gotoxy(p.x = 0, p.y);
    // fall through to VT52_CHR_DOWN
    case VT52_CHR_DOWN:
        if (p.y != h - 1) {
            gotoxy(p.x, p.y + 1);
        } else {
            scrup();
        }
        break;
    case VT52_CHR_LEFT:
        if (p.x > 0) {
            gotoxy(p.x - 1, p.y);
        } else if (p.y > 0) {
            gotoxy(w - 1, p.y - 1);
        }
        break;
    }
}

