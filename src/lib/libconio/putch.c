
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
            if (_conio.bgcolor) {
                unsigned char bits = _conio.fontpack ? _conio.fontbase & 128 ? 0xF : 0xF0 : 0xFF;
                asm {
                    ldb     _HORBYT
                    ldx     _CURPOS
                }
#define COPY_OR() asm{ lda ,x} asm{ ora bits} asm{ sta ,x} asm{ abx}
                COPY_OR();
                COPY_OR();
                COPY_OR();
                COPY_OR();
                COPY_OR();
                COPY_OR();
                COPY_OR();
                COPY_OR();
            } else {
                if (_conio.fontpack) {
                    unsigned char bits = _conio.fontbase & 128 ? 0xF0 : 0xF;
                    asm {
                        ldb     _HORBYT
                        ldx     _CURPOS
                    }
#define COPY_AND() asm{ lda ,x} asm{ anda bits} asm{ sta ,x} asm{ abx}
                    COPY_AND();
                    COPY_AND();
                    COPY_AND();
                    COPY_AND();
                    COPY_AND();
                    COPY_AND();
                    COPY_AND();
                    COPY_AND();
                }
            }
            unsigned char* src = _conio.fontdata + (((unsigned)(c - 32) + _conio.fontbase) << 3);
            if (_conio.fontpack) {
                asm {
                    ldb     _HORBYT
                    ldx     _CURPOS
                    ldy     src
                }
#define COPY_XOR(INDEX) asm{ lda ,x} asm{ eora INDEX,y} asm{ sta ,x} asm{ abx}
                COPY_XOR(0)
                COPY_XOR(1)
                COPY_XOR(2)
                COPY_XOR(3)
                COPY_XOR(4)
                COPY_XOR(5)
                COPY_XOR(6)
                COPY_XOR(7)
            } else {
                asm {
                    ldb     _HORBYT
                    ldx     _CURPOS
                    ldy     src
                }
#define COPY_CPY(INDEX) asm{ lda INDEX,y} asm{ sta ,x} asm{ abx}
                COPY_CPY(0)
                COPY_CPY(1)
                COPY_CPY(2)
                COPY_CPY(3)
                COPY_CPY(4)
                COPY_CPY(5)
                COPY_CPY(6)
                COPY_CPY(7)
            }
        }
    }
    putrt();
    return c;
}

