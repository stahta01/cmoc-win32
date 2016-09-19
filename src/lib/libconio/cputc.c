
#include "_conio.h"
#include <stdbool.h>

int _vt52mode = ASCII_NUL;

void cputc(int c)
{
    switch (_vt52mode) {
    case ASCII_ESC:
        switch (c) {
        case 'A':
            putup();
            _vt52mode = ASCII_NUL;
            break;
        case 'B':
            putdn();
            _vt52mode = ASCII_NUL;
            break;
        case 'C':
            putrt();
            _vt52mode = ASCII_NUL;
            break;
        case 'D':
            putlt();
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
            putlt();
            break;
        case ASCII_HT:
            putrt();
            break;
        case ASCII_LF:
        case ASCII_CR:
            putlf();
            break;
        default:
            putch(c);
            break;
        }
    }
}

