
#include "_graph.h"

int _setactivepage(int page)
{
    int result = _getactivepage();
    page = ((word)_grpram << 8) + (page - 1) * 1536;
    _endgrp = page + (_endgrp - _beggrp);
    _beggrp = page;
    return result;
}

