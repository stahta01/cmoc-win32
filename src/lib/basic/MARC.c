
#include "_basic.h"

void MARC(int x, int y, int w, int h, int s, int e, byte c)
{
    _setcolor(c);
    _arc(x, y, w, h, s, e);
}

