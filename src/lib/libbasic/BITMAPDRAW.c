
#include <basic.h>

void BITMAPDRAW(BITMAP* dst, int x, int y, BITMAP* src)
{
    BITMAPCOPYRECT(dst, x, y, x + src->width, y + src->height, src, 0, 0, src->width, src->height);
}

