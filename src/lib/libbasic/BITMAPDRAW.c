
#include <basic.h>

void BITMAPDRAW(BITMAP* dst, int x, int y, BITMAP* src)
{
    zX1 = x;
    zY1 = y;
    zX2 = x + src->width;
    zY2 = y + src->height;
    zU1 = 0;
    zV1 = 0;
    zU2 = src->width;
    zV2 = src->height;
    _COPYRECT(dst->data, dst->width, dst->height, src->data, src->width);
}



