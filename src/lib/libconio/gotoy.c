
#include "_conio.h"

void gotoy(unsigned char y)
{
    if (isvidram()) {
        _curpos = (_curpos & 0xfe1f) | (((unsigned)y) << 5);
    } else {
        _curpos = _beggrp + (((unsigned)y * ((unsigned)_horbyt << 3)) | (_curpos & (_horbyt - 1)));
    }
}

