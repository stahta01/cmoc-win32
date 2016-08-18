
#include <basic.h>

void SCREEN(int agr, int css)
{
    if (agr) {
        byte page = PEEK(_BEGGRP) >> 1;
        for (byte i = 0; i < 7; i++) {
            POKE(65478 + (i << 1) + (page & 1), true);
            page >>= 1;
        }
        byte mode = _pmode + 3;
        POKE(0xff22, PEEK(0xff22) & 0x8F | (mode << 4));
        if (mode == 7) {
            mode = 6;
        }
        for (word i = 0xffc0; i < 0xffc5; i += 2) {
            POKE(i + (mode & 1), true);
            mode >>= 1;
        }
        POKE(0xff22, PEEK(0xff22) | 128);
    } else {
        POKE(0xff22, PEEK(0xff22) & 127);
    }
    if (css) {
        POKE(0xff22, PEEK(0xff22) | 8);
    } else {
        POKE(0xff22, PEEK(0xff22) & 247);
    }
}





