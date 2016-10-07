
#include "_conio.h"

void cursormove(int vt52_char)
{
    int x, y, w, h;
    screensize(&w, &h);
    wherexy(&x, &y);
    switch (vt52_char) {
    case VT52_CHR_HOME:
        x = y = 0;
        break;
    case VT52_CHR_UP:
        if (y > 0) {
            y--;
        }
        break;
    case VT52_CHR_RIGHT:
        if (x != w - 1) {
            x++;
            break;
        }
        x = 0;
    // fall through to VT52_CHR_DOWN
    case VT52_CHR_DOWN:
        if (y != h - 1) {
            y++;
        } else {
            screenmove(VT52_CHR_UP);
        }
        break;
    case VT52_CHR_LEFT:
        if (x > 0) {
            x--;
        } else if (y > 0) {
            x = w - 1;
            y --;
        }
        break;
    }
    gotoxy(x, y);
}

