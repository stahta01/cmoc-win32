
#include "_conio.h"

byte _charsetgroups[] = {0 << 5, 3 << 5, 2 << 5, 0 << 5};

void _putstr(char* str)
{
    for (char chr; chr = *str++;) {
        if (_is_coco3_mode) {
            system_cputc(chr);
        } else {
            if (isvidram()) {
                chr = (chr & 31) | _charsetgroups[chr >> 5];
                if (_conio.revers) {
                    chr &= 64 ^ -1;
                }
                *(char*)_curpos = chr;
            } else if (_conio.outchar) {
                _conio.outchar(chr);
            }
            cursormove(VT52_CHR_RIGHT);
        }
    }
}

