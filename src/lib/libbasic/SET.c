
#include <basic.h>
#include <motorola.h>

byte _chr_set[2][2] = {{128|8, 128|2}, {128|4, 128|1}};
byte _chr_clr[2][2] = {{240|7, 240|13}, {240|11, 240|14}};

#define PTR _PTRTYPE(_TEMPTR, byte)
#define VIDLOC(X,Y) (byte*)(_VIDRAM + ((word)((Y) & 30) << 4) + (word)(((X) & 63) >> 1))

void SET(int x, int y, byte c)
{
    PTR = VIDLOC(x, y);
    *PTR = c ?
           _chr_set[x & 1][y & 1] | ((c - 1) << 4) | ((*PTR & 128 ? *PTR : 0) & 15) :
           _chr_clr[x & 1][y & 1] & (*PTR & 128 ? *PTR : (15+128));
}

int POINT(int x, int y)
{
    PTR = VIDLOC(x, y);
    byte c = *PTR;
    return c & 128 ? ((c & 15) & _chr_set[x & 1][y & 1]) ? ((c >> 4) & 7) + 1 : 0 : -1;
}




