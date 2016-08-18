
#include <basic.h>

void SETELLIPSE(int x, int y, int w, int h, byte c)
{
    SETARC(x, y, w, h, 0, 256, c);
}

