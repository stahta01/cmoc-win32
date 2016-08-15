
#include <basic.h>
#include <stdlib.h>

byte _chr_set[2][2] = {{128|8, 128|2}, {128|4, 128|1}};
byte _chr_clr[2][2] = {{240|7, 240|13}, {240|11, 240|14}};

#define PTR ((byte*)_temptr)

void SET(byte x, byte y, byte c)
{
    PTR = (byte*)(_VIDRAM + ((word)(y & 30) << 4) + (word)((x & 63) >> 1));
    *PTR = c ?
           _chr_set[x & 1][y & 1] | ((c - 1) << 4) | ((*PTR & 128 ? *PTR : 0) & 15) :
           _chr_clr[x & 1][y & 1] & (*PTR & 128 ? *PTR : 15);
}




