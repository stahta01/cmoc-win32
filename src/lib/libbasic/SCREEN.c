
#include <basic.h>
#include <coco/cocodefs.h>

void SCREENSETUP(void)
{
    byte mode, sect;
    if (PEEK(_PIA1BD) & 128) {
        sect = PEEK(_BEGGRP) >> 1;
        mode = _pmode + 3;
    } else {
        sect = 2;
        mode = 0;
    }
    ((byte*)_F0CLR)[sect & 1] = true;
    sect >>= 1;
    ((byte*)_F1CLR)[sect & 1] = true;
    sect >>= 1;
    ((byte*)_F2CLR)[sect & 1] = true;
    sect >>= 1;
    ((byte*)_F3CLR)[sect & 1] = true;
    sect >>= 1;
    ((byte*)_F4CLR)[sect & 1] = true;
    sect >>= 1;
    ((byte*)_F5CLR)[sect & 1] = true;
    sect >>= 1;
    ((byte*)_F6CLR)[sect & 1] = true;
    sect >>= 1;

    byte v = _min(mode, 6);
    POKE(_V2CLR + ((v & 4) ? 1 : 0), true);
    POKE(_V1CLR + ((v & 2) ? 1 : 0), true);
    POKE(_V0CLR + ((v & 1) ? 1 : 0), true);

    POKE(_PIA1BD, (PEEK(_PIA1BD) & 0x8f) | (mode << 4));
}

void SCREEN(int agr, int css)
{
    if (agr) {
        asm {
            lda     _PIA1BD
            ora     #128
            sta     _PIA1BD
        }
    } else {
        asm {
            lda     _PIA1BD
            anda    #127
            sta     _PIA1BD
        }
    }
    if (css) {
        asm {
            lda     _PIA1BD
            ora     #8
            sta     _PIA1BD
        }
    } else {
        asm {
            lda     _PIA1BD
            anda    #247
            sta     _PIA1BD
        }
    }
    SCREENSETUP();
}

