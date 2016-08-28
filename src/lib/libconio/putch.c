
#include "_conio.h"

unsigned char _charsetgroups[] = {0 << 5, 3 << 5, 2 << 5, 0 << 5};

char putch(char c)
{
    if (isvidram()) {
        c = (c & 31) | _charsetgroups[c >> 5];
        if (_conio.revers) {
            c &= 64^-1;
        }
        *(unsigned char*)_curpos = c;
    } else {
        if (isgrpram()) {
            unsigned char horbyt = _horbyt;
            if (_conio.bgcolor) {
                unsigned char bits = _conio.fontpack ? _conio.fontbase & 128 ? 0xF : 0xF0 : 0xFF;

#define COPY_OR() asm{ lda ,x} asm{ ora bits} asm{ sta ,x} asm{ abx}

                asm {
                    ldb     _HORBYT
                    ldx     _CURPOS
                }
                COPY_OR();
                COPY_OR();
                COPY_OR();
                COPY_OR();
                COPY_OR();
                COPY_OR();
                COPY_OR();
                COPY_OR();
            } else {
                unsigned char bits = _conio.fontpack ? _conio.fontbase & 128 ? 0xF0 : 0xF : 0;

#define COPY_AND() asm{ lda ,x} asm{ anda bits} asm{ sta ,x} asm{ abx}

                asm {
                    ldb     _HORBYT
                    ldx     _CURPOS
                }
                COPY_AND();
                COPY_AND();
                COPY_AND();
                COPY_AND();
                COPY_AND();
                COPY_AND();
                COPY_AND();
                COPY_AND();
            }
            unsigned char* src = _conio.fontdata + (((unsigned)(c - 32) + _conio.fontbase) << 3);

#define COPY_XOR(INDEX) asm{ lda ,x} asm{ eora INDEX,y} asm{ sta ,x} asm{ abx}

            asm {
                ldb     _HORBYT
                ldx     _CURPOS
                ldy     src
            }
            COPY_XOR(0)
            COPY_XOR(1)
            COPY_XOR(2)
            COPY_XOR(3)
            COPY_XOR(4)
            COPY_XOR(5)
            COPY_XOR(6)
            COPY_XOR(7)
        }
    }
    putrt();
    return c;
}

