
#include "_basic.h"

void MLINE(int x1, int y1, int x2, int y2, byte c)
{
    _setcolor(c);
    _moveto(x1, y1);
    _lineto(x2, y2);
}

