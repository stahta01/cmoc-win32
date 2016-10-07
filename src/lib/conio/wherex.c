
#include "_conio.h"

int wherex(void)
{
    return _is_coco3_mode ? (int)_h_cursx : isvidram() ? (int)(_curpos & 31) : _gettextpositionx();
}

