
#include "_conio.h"

void cursormove(int chr)
{
    int x, y, w, h;
    screensize(&w, &h);
    wherexy(&x, &y);
    switch (chr) {
    case VT52_CHR_HOME:
        x = y = 0;
        break;
    case VT52_CHR_UP:
        if (y > 0) {
            y--;
        }
        break;
    case ASCII_HT:
    case VT52_CHR_RIGHT:
        if (x != w - 1) {
            x++;
            break;
        }
    case ASCII_LF:
    case ASCII_CR:
        x = 0;
    case VT52_CHR_DOWN:
        if (y != h - 1) {
            y++;
        } else {
            screenmove(VT52_CHR_UP);
        }
        break;
    case ASCII_BS:
    case VT52_CHR_LEFT:
        if (x > 0) {
            x--;
        } else if (y > 0) {
            x = w - 1;
            y--;
        }
        break;
    }
    gotoxy(x, y);
}

