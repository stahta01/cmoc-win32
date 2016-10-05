
#include "_conio.h"

int wherex(void)
{
    return _hrwidth ? coco3_wherex() : isvidram() ? (int)(_curpos & 31) : _gettextpositionx();
}

