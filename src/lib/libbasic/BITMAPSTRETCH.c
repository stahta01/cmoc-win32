
#include <basic.h>

void BITMAPSTRETCH(BITMAP* dst, int x1, int y1, int x2, int y2, BITMAP* src)
{
    BITMAPCOPYRECT(dst, x1, y1, x2, y2, src, 0, 0, src->width, src->height);
}

