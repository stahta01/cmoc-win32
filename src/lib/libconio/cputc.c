
#include "_conio.h"
#include <stdbool.h>

int _vt52mode;

void cputc(int c)
{
    if (_vt52mode) {
        switch (c) {
        case 'A':
            putup();
            break;
        case 'B':
            putdn();
            break;
        case 'C':
            putrt();
            break;
        case 'D':
            putlt();
            break;
        }
        _vt52mode = 0;
    } else {
        switch (c) {
        case ASCII_ESC:
            _vt52mode = 1;
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

