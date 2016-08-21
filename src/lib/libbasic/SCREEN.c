
#include <basic.h>

void SCREEN(int agr, int css)
{
    if (agr) {
        byte page = PEEK(_BEGGRP) >> 1;
        for (byte i = 0; i < 7; i++) {
            POKE(0xffc6 + (i << 1) + (page & 1), true);
            page >>= 1;
        }
        byte mode = _pmode + 3;
        if (mode == 7) {
            mode = 6;
        }
        POKE(0xffc4 + ((mode & 4) ? 1 : 0), 0);
        POKE(0xffc2 + ((mode & 2) ? 1 : 0), 0);
        POKE(0xffc0 + ((mode & 1) ? 1 : 0), 0);
        POKE(0xff22, (PEEK(0xff22) & 7) | (128 + ((_pmode + 3) << 4)));
    } else {
        POKE(0xff22, PEEK(0xff22) & 127);
    }
    if (css) {
        POKE(0xff22, PEEK(0xff22) | 8);
    } else {
        POKE(0xff22, PEEK(0xff22) & 247);
    }
}





