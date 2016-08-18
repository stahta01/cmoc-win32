
#include <basic.h>

void PMODE(int mode, int page)
{
    word i;
    page = (page << 1) + 6;
    for (i = 0; i < 7; i++) {
        POKE(65478 + (i << 1) + (page & 1), true);
        page >>= 1;
    }
    mode = _min(_max(mode, 0), 4);
    _pmode = (byte)mode;
    _beggrp = 0x0C00;
    _endgrp = _beggrp + (24 << 8);
    _horbyt = (_pmode == 0 || _pmode == 2) ? 16 : 32;
    mode += 3;
    POKE(0xff22, PEEK(0xff22) & 0x8F | (mode << 4));
    if (mode == 7) {
        mode = 6;
    }
    for (i = 0xffc0; i < 0xffc5; i += 2) {
        POKE(i + (mode & 1), true);
        mode >>= 1;
    }
}


