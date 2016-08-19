
#include <basic.h>

BITMAP* BITMAPCREATE(word width, word height)
{
    return BITMAPCREATE2(width, height, (byte*) calloc(width, height), width, true);
}

