
#include "_conio.h"

unsigned char wherey(void)
{
    if (isvidram()) {
        return (unsigned char)(_curpos >> 5) & 15;
    } else {
        unsigned pos = _curpos - _beggrp;
        if (_horbyt == 16) {
            pos >>= 7;
        } else {
            pos >>= 8;
        }
        return (unsigned char)pos;
    }
}

