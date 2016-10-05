
#include "_conio.h"

byte _charsetgroups[] = {0 << 5, 3 << 5, 2 << 5, 0 << 5};

int putch(int c)
{
    if (isvidram()) {
        c = (c & 31) | _charsetgroups[c >> 5];
        if (_conio.revers) {
            c &= 64 ^ -1;
        }
        *(char*)_curpos = (char)c;
    } else {
        if (_conio.outchar) {
            _conio.outchar(c);
        }
    }
    cursormove(VT52_CHR_RIGHT);
    return c;
}

