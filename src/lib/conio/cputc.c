
#include "_conio.h"
#include <stdbool.h>

int _vt52mode = ASCII_NUL;

void cputc(int c)
{
    switch (_vt52mode) {
    case ASCII_ESC:
        switch (c) {
        case VT52_CHR_UP:
            cursormove(c);
            _vt52mode = ASCII_NUL;
            break;
        case VT52_CHR_DOWN:
            cursormove(c);
            _vt52mode = ASCII_NUL;
            break;
        case VT52_CHR_RIGHT:
            cursormove(c);
            _vt52mode = ASCII_NUL;
            break;
        case VT52_CHR_LEFT:
            cursormove(c);
            _vt52mode = ASCII_NUL;
            break;
        case 'H':
            gotoxy(0, 0);
            _vt52mode = ASCII_NUL;
            break;
        case 'Y':
            _vt52mode = c;
            break;
        }
        break;
    case 'Y':
        gotoy(c - 32);
        _vt52mode = 'X';
        break;
    case 'X':
        gotox(c - 32);
        _vt52mode = ASCII_NUL;
        break;
    default:
        _vt52mode = ASCII_NUL;
        switch (c) {
        case ASCII_ESC:
            _vt52mode = ASCII_ESC;
            break;
        case ASCII_BS:
            cursormove(VT52_CHR_LEFT);
            break;
        case ASCII_HT:
            cursormove(VT52_CHR_RIGHT);
            break;
        case ASCII_LF:
        case ASCII_CR:
            _cputlf();
            break;
        default:
            putch(c);
            break;
        }
    }
}

