
#include <basic.h>

void BITMAPCOPYRECT(BITMAP* dst, int x1, int y1, int x2, int y2, BITMAP* src,
                    int u1, int v1, int u2, int v2)
{
    zX1 = x1;
    zY1 = y1;
    zX2 = x2;
    zY2 = y2;
    zU1 = u1;
    zV1 = v1;
    zU2 = u2;
    zV2 = v2;
    BYTESCOPYRECT(dst->data, dst->width, dst->height, src->data, src->width);
}


