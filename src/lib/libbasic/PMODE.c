
#include <basic.h>

void PMODE(int mode, int page)
{
    page += 1; // Dont use page 1
    _beggrp = page * 0x600;
    _endgrp = _beggrp + (24 << 8);
    mode = _min(_max(mode, 0), 4);
    _pmode = (byte)mode;
    _horbyt = (_pmode == 0 || _pmode == 2) ? 16 : 32;

    CLIP(2, 2, 254, 190); // TODO: Set this correctly
}



