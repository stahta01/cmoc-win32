
#include "_conio.h"

int _vt52mode = ASCII_NUL;

byte _charsetgroups[] = {0 << 5, 3 << 5, 2 << 5, 0 << 5};

void cputs(char* str)
{
    bank_t bank;
    if (_is_coco3_mode) {
        bank = bank_set(13);
    }
    for (int chr; chr = *str++;) {
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
        case VT52_CHR_XPOS:
            gotox(chr - 32);
            _vt52mode = ASCII_NUL;
            break;
        case VT52_CHR_YPOS:
            gotoy(chr - 32);
            _vt52mode = VT52_CHR_XPOS;
            break;
        default:
            _vt52mode = ASCII_NUL;
            switch (chr) {
            case ASCII_ESC:
                _vt52mode = ASCII_ESC;
                break;
            case ASCII_BS:
            case ASCII_HT:
            case ASCII_LF:
            case ASCII_CR:
                cursormove(chr);
                break;
            default:
                if (_is_coco3_mode) {
                    *(word*)(_h_crsloc + 0xa000) = (chr << 8) | _h_crsatt;
                } else if (isvidram()) {
                    chr = (chr & 31) | _charsetgroups[chr >> 5];
                    if (_conio.revers) {
                        chr &= 64 ^ -1;
                    }
                    *(byte*)_curpos = (byte)chr;
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

