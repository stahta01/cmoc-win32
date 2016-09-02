
#include "_graph.h"

int _gettextpositiony(void)
{
    unsigned result = _curpos - _beggrp;
    // CMOC produces faster but bigger code if we seperate this. Should we?
    if (_horbyt == 16) {
        result >>= 7;
    } else {
        result >>= 8;
    }
    return result;
}

