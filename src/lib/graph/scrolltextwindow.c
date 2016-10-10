
#include "_graph.h"

// TODO: Only supports up by one line at this stage

void  _scrolltextwindow(int rows)
{
    switch (rows) {
    case _GSCROLLUP:
        word line = (word)_horbyt << 3;
        memcpy16((void*)_beggrp, (void*)(_beggrp + line), ((_endgrp - _beggrp) - line) >> 4);
        memset((void*)(_endgrp - line), pixel2_all[_bakcol], line);
        break;
    }
}

