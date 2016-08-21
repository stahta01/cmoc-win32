
#include <basic.h>

void PMODE(int mode, int page)
{
    _beggrp = (page + 1) * 0x600; // Dont use page 1
    _endgrp = _beggrp + (24 << 8); // TODO: Set correct size
    _pmode = (byte)_min(_max(mode, 0), 4);
    _horbyt = (_pmode == 0 || _pmode == 2) ? 16 : 32;

    CLIP(2, 2, 254, 190); // TODO: Set this correctly
}



