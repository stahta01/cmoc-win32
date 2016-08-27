
#include "_conio.h"

void scrup(void)
{
    if (isvidram()) {
        memmove(_VIDRAM, _VIDRAM + 32, 32 * 15);
        memset(_VIDRAM + 32 * 15, 96, 32);
    } else {
        if (isgrpram()) {
            unsigned line = (unsigned)_horbyt << 3;
            memmove((void*)_beggrp, (void*)(_beggrp + line), (_endgrp - _beggrp) - line);
            memset((void*)(_endgrp - line), _bakcol ? 255 : 0, line);
        }
    }
}

