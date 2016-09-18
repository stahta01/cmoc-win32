
#include "_graph.h"

// TODO: Only supports up by one line at this stage

void  _scrolltextwindow(int rows)
{
    switch (rows) {
    case _GSCROLLUP:
        unsigned line = (unsigned)_horbyt << 3;
        _memcpy16((void*)_beggrp, (void*)(_beggrp + line), ((_endgrp - _beggrp) - line) >> 4);
        //memcpy((void*)_beggrp, (void*)(_beggrp + line), (_endgrp - _beggrp) - line);
        memset((void*)(_endgrp - line), _pset2_all[_bakcol], line);
        break;
    }
}

