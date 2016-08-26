
#include "basicdefs.h"

void PSECT(int sect)
{
    _beggrp = sect * 0x200;
    _endgrp = _beggrp + (0x600 << ((_pmode + 1) >> 1));
    //SCREENSETUP();
}

void PMODE(int mode, int page)
{
    _pmode = (byte)_min(_max(mode, 0), 4);
    _horbyt = (_pmode == 0 || _pmode == 2) ? 16 : 32;
    PSECT((page + 1) * 3);
    CLIP(2, 2, 254, 190); // TODO: Set this correctly
}

