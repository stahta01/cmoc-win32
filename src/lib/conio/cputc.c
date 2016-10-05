
#include "_conio.h"
#include <stdbool.h>

int _vt52mode = ASCII_NUL;

void cputc(int chr)
{
    switch (_vt52mode) {
    case ASCII_ESC:
        switch (chr) {
        case VT52_CHR_UP:
        case VT52_CHR_DOWN:
        case VT52_CHR_RIGHT:
        case VT52_CHR_LEFT:
            cursormove(chr);
            _vt52mode = ASCII_NUL;
            break;
        case VT52_CHR_HOME:
            gotoxy(0, 0);
            _vt52mode = ASCII_NUL;
            break;
        case 'Y':
            _vt52mode = chr;
            break;
        }
        break;
    case 'Y':
        gotoy(chr - 32);
        _vt52mode = 'X';
        break;
    case 'X':
        gotox(chr - 32);
        _vt52mode = ASCII_NUL;
        break;
    default:
        _vt52mode = ASCII_NUL;
        switch (chr) {
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
            if (_is_coco3_mode) {
                system_cputc('\r');
            } else {
                cursormove(VT52_CHR_DOWN);
                gotox(0);
            }
            break;
        default:
            putch(chr);
            break;
        }
    }
}

