
#include "_conio.h"

int whereat(void)
{
    return _is_coco3_mode ? coco3_whereat() : isvidram() ? (int)_curpos - _VIDRAM :
           _gettextpositionat();
}

