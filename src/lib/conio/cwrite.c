
#include "_conio.h"

int _vt52mode = VT52_CHR_NULL;

byte _charsetgroups[] = {0 << 5, 3 << 5, 2 << 5, 0 << 5};

void cwrite(char* str, size_t size)
{
    bank_t bank;
    bool is4080 = _is_coco3_mode;
    bool is32 = isvidram();

    if (is4080) {
        bank = bank_set(13);
    }
    while (size--) {
        int chr = *str++;
        if (_vt52mode) {
            switch (_vt52mode) {
            case VT52_CHR_ESCAPE:
                switch (chr) {
                case VT52_CHR_UP:
                case VT52_CHR_DOWN:
                case VT52_CHR_RIGHT:
                case VT52_CHR_LEFT:
                case VT52_CHR_HOME:
                    cursormove(chr);
                    _vt52mode = VT52_CHR_NULL;
                    break;
                case VT52_CHR_YPOS:
                    _vt52mode = VT52_CHR_YPOS;
                    break;
                }
                break;
            case VT52_CHR_XPOS:
                gotox(chr - 32);
                _vt52mode = VT52_CHR_NULL;
                break;
            case VT52_CHR_YPOS:
                gotoy(chr - 32);
                _vt52mode = VT52_CHR_XPOS;
                break;
            default:
                _vt52mode = VT52_CHR_NULL;
                break;
            }
        } else {
            switch (chr) {
            case ASCII_BS:
            case ASCII_HT:
            case ASCII_LF:
            case ASCII_CR:
                cursormove(chr);
                break;
            case ASCII_ESC:
                _vt52mode = VT52_CHR_ESCAPE;
                break;
            default:
                if (is4080) {
                    *(word*)(_h_crsloc + 0xa000) = (chr << 8) | _h_crsatt;
                } else if (is32) {
                    chr = (chr & 31) | _charsetgroups[chr >> 5];
                    if (_conio.revers) {
                        // todo: fix this
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
    if (is4080) {
        bank_set(bank);
    }
}

