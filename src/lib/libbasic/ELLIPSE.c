
#include <basic.h>

void ELLIPSE(int x, int y, int w, int h, byte c)
{
    ARC(x, y, w, h, 0, 256, c);
}

