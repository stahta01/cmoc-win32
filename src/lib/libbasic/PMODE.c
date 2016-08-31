
#include <basic.h>

void PSECT(int sect)
{
    _beggrp = sect * 0x200;
    _endgrp = _beggrp + (0x600 << ((_pmode + 1) >> 1));
    //SCREENSETUP();
}

void PMODE(int mode, int page)
{
    char s[] = "PMODE?,?";
    s[5] = '0' + (char)mode;
    s[7] = '0' + (char)page;
    system(s);
    MCLIP(2, 2, 254, 190); // TODO: Set this correctly
}

