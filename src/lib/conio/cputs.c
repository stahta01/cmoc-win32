
#include "_conio.h"

int _vt52mode = ASCII_NUL;

byte _charsetgroups[] = {0 << 5, 3 << 5, 2 << 5, 0 << 5};

void cputs(char* str)
{
    bank_t bank;
    if (_is_coco3_mode) {
        bank = bank_set(13);
    }
    for (byte chr; chr = *str++;) {
        switch (_vt52mode) {
        case ASCII_ESC:
            switch (chr) {
            case VT52_CHR_UP:
            case VT52_CHR_DOWN:
            case VT52_CHR_RIGHT:
            case VT52_CHR_LEFT:
            case VT52_CHR_HOME:
                cursormove(chr);
                _vt52mode = ASCII_NUL;
                break;
            case VT52_CHR_YPOS:
                _vt52mode = chr;
                break;
            }
            break;
        case VT52_CHR_YPOS:
            gotoy(chr - 32);
            _vt52mode = VT52_CHR_XPOS;
            break;
        case VT52_CHR_XPOS:
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
                cursormove(VT52_CHR_DOWN);
                gotox(0);
                break;
            default:
                if (_is_coco3_mode) {
                    *(byte*)(_h_crsloc + 0xa000) = chr;
                } else if (isvidram()) {
                    chr = (chr & 31) | _charsetgroups[chr >> 5];
                    if (_conio.revers) {
                        chr &= 64 ^ -1;
                    }
                    *(byte*)_curpos = chr;
                } else if (_conio.outchar) {
                    _conio.outchar(chr);
                }
                cursormove(VT52_CHR_RIGHT);
                break;
            }
        }
    }
    if (_is_coco3_mode) {
        bank_set(bank);
    }
}

