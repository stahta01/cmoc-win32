
#include "_conio.h"

int whereat(void)
{
    return _is_coco3_mode ? (int)((_h_crsloc - 0x2000) >> 1) : isvidram() ? (int)_curpos - _VIDRAM :
           _gettextpositionat();
}

