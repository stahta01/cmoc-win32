
#include <basic.h>

BITMAP* BITMAPCREATE2(word width, word height, byte* data, word bytesperline, bool freememory)
{
    BITMAP* bitmap = (BITMAP*)calloc(sizeof(BITMAP), 1);
    bitmap->width = width;
    bitmap->height = height;
    bitmap->data = data;
    bitmap->bytesperline = bytesperline;
    bitmap->freememory = freememory;
    return bitmap;
}


