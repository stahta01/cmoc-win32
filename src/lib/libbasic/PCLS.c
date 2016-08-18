
#include <basic.h>
#include <string.h>

void PCLS(byte c)
{
    if (_pmode & 1) {
        c &= 3;
        c = (c << 6) | (c << 4) | (c << 2) | c;
    } else {
        if (c) {
            c = 255;
        }
    }
    memset((void*)_beggrp, c, _endgrp - _beggrp);
}





