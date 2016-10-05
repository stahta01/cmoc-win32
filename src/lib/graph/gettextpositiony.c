
#include "_graph.h"

int _gettextpositiony(void)
{
    word result = _curpos - _beggrp;
    if (_horbyt == 16) {
        result >>= 7;
    } else {
        result >>= 8;
    }
    return result;
}

