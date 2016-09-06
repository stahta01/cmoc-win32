
#include "_graph.h"

void _outchar(int c)
{
    c -= 32;
    if (fontinfo.type) {
        c <<= 1;
    }
    unsigned char* src = fontinfo.data + (((unsigned)c + fontinfo.base) << 3);
    int bkcolor = _getbkcolor();

    if (bkcolor || fontinfo.type) {
        // First we clear the bits. (We could use clr for non-packed fonts)

        unsigned char bits = fontinfo.type ? fontinfo.base & 1 ? 0xF0 : 0xF : 0x0;

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
#undef COPY_AND

        // Next we set the bits to the background color

        bits = _pset2_all[bkcolor];
        if (fontinfo.type) {
            bits &= fontinfo.base & 1 ? 0xF : 0xF0;
        }

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
#undef COPY_OR

        // Now we xor the font onto the background color

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
#undef COPY_XOR
    } else {
        // For a black screen and unpacked fonts, we just need to copy the font.

#define COPY_CPY(INDEX) asm{ lda INDEX,y} asm{ sta ,x} asm{ abx}
        asm {
            ldb     _HORBYT
            ldx     _CURPOS
            ldy     src
        }
        COPY_CPY(0)
        COPY_CPY(1)
        COPY_CPY(2)
        COPY_CPY(3)
        COPY_CPY(4)
        COPY_CPY(5)
        COPY_CPY(6)
        COPY_CPY(7)
#undef COPY_CPY
    }
}

