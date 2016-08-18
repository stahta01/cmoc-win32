
#include <basic.h>

void SETELLIPSE(int x, int y, int w, int h, byte c, bool fill)
{
    SETARC(x, y, w, h, 0, 256, c, fill);
}

