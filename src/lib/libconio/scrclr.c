
#include "_conio.h"

void scrclr(void)
{
    if (isvidram()) {
        memset(_VIDRAM, 96, 0x200);
    } else {
        if (isgrpram()) {
            memset((void*)_beggrp, _conio.bgcolor ? 255 : 0, _endgrp - _beggrp);
        }
    }
}

