
#include <basic.h>

void LELLIPSE(int x, int y, int w, int h, byte c)
{
    LARC(x, y, w, h, 0, 256, c);
}

