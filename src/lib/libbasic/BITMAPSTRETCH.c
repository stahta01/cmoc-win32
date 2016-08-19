
#include <basic.h>

void BITMAPSTRETCH(BITMAP* dst, int x1, int y1, int x2, int y2, BITMAP* src)
{
    zX1 = x1;
    zY1 = y1;
    zX2 = x2;
    zY2 = y2;
    zU1 = 0;
    zV1 = 0;
    zU2 = src->width;
    zV2 = src->height;
    BYTESCOPYRECT(dst->data, dst->width, dst->height, src->data, src->width);
}


