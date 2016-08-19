
#include <basic.h>

BITMAP* BITMAPCREATE(word width, word height)
{
    return BITMAPATTACH(width, height, (byte*) calloc(width, height), width, true);
}

