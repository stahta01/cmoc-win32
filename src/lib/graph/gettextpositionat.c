
#include "_graph.h"

int _gettextpositionat(void)
{
    word result = _curpos - _beggrp;
    result = (result & ((word)_horbyt - 1)) + ((result & (_horbyt == 16 ? 0xff80 : 0xff00)) >> 3);
    if (fontinfo.packed) {
        result = (result << 1) | (fontinfo.base & 1);
    }
    return result;
}

