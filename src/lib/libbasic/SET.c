
#include <basic.h>
#include <motorola.h>

byte _chr_set[2][2] = {{128|8, 128|2}, {128|4, 128|1}};
byte _chr_clr[2][2] = {{240|7, 240|13}, {240|11, 240|14}};

#define VIDLOC(x,y) (byte*)(_VIDRAM + ((word)((y) & 30) << 4) + (word)(((x) & 63) >> 1))

void _SET(void)
{
    GR_P = VIDLOC(zX, zY);
    *GR_P = zFC ?
           _chr_set[zX & 1][zY & 1] | ((zFC - 1) << 4) | ((*GR_P & 128 ? *GR_P : 0) & 15) :
           _chr_clr[zX & 1][zY & 1] & (*GR_P & 128 ? *GR_P : 0x8f);
}

void SET(int x, int y, byte c)
{
    zX = x;
    zY = y;
    zFC = c;
    _SET();
}

int _POINT(void)
{
    GR_P = VIDLOC(zX, zY);
    zWC = *GR_P;
    return zWC & 128 ? ((zWC & 15) & _chr_set[zX & 1][zY & 1]) ? ((zWC >> 4) & 7) + 1 : 0 : -1;
}

int POINT(int x, int y)
{
    zX = x;
    zY = y;
    return _POINT();
}




