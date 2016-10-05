
#include "_conio.h"

int wherex(void)
{
    return _is_coco3_mode ? coco3_wherex() : isvidram() ? (int)(_curpos & 31) : _gettextpositionx();
}

