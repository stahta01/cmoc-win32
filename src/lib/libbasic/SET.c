
#include <basic.h>
#include <motorola.h>

byte _chr_set[2][2] = {{128|8, 128|2}, {128|4, 128|1}};
byte _chr_clr[2][2] = {{240|7, 240|13}, {240|11, 240|14}};

#define p _PTRTYPE(_TEMPTR, byte)
#define VIDLOC(x,y) (byte*)(_VIDRAM + ((word)((y) & 30) << 4) + (word)(((x) & 63) >> 1))

void _SET(void)
{
    p = VIDLOC(X, Y);
    *p = C ?
           _chr_set[X & 1][Y & 1] | ((C - 1) << 4) | ((*p & 128 ? *p : 0) & 15) :
           _chr_clr[X & 1][Y & 1] & (*p & 128 ? *p : (15+128));
}

void SET(int x, int y, byte c)
{
    X = x;
    Y = y;
    C = c;
    _SET();
}

int _POINT(void)
{
    p = VIDLOC(X, Y);
    byte c = *p;
    return c & 128 ? ((c & 15) & _chr_set[X & 1][Y & 1]) ? ((c >> 4) & 7) + 1 : 0 : -1;
}

int POINT(int x, int y)
{
    X = x;
    Y = y;
    return _POINT();
}




