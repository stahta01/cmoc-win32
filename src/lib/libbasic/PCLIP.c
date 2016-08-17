
#include <basic.h>

void PCLIP(int x1, int y1, int x2, int y2)
{
    _basic.pclip.x1 = x1;
    _basic.pclip.y1 = y1;
    _basic.pclip.x2 = x2;
    _basic.pclip.y2 = y2;
}


