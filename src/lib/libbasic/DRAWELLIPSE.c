
#include <basic.h>

void DRAWELLIPSE(byte x, byte y, int w, int h, byte c)
{
    DRAWARC(x, y, w, h, 0, 64, c);
    DRAWARC(x, y, w, h, 0, -64, c);
    DRAWARC(x, y, w, h, 128, 64, c);
    DRAWARC(x, y, w, h, 128, 192, c);
}

