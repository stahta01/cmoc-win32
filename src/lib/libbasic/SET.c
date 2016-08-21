
#include <basic.h>
#include <motorola.h>

byte _chr_set[2][2] = {{128|8, 128|2}, {128|4, 128|1}};
byte _chr_clr[2][2] = {{240|7, 240|13}, {240|11, 240|14}};

#define VIDLOC(x,y) (byte*)(_VIDRAM + ((word)((y) & 30) << 4) + (word)(((x) & 63) >> 1))

void SET(int x, int y, byte c)
{
    byte* p = VIDLOC(x, y);
    *p = c ?
         _chr_set[x & 1][y & 1] | ((c - 1) << 4) | ((*p & 128 ? *p : 0) & 15) :
         _chr_clr[x & 1][y & 1] & (*p & 128 ? *p : 0x8f);
}

int POINT(int x, int y)
{
    byte i = *VIDLOC(x, y);
    return i & 128 ? ((i & 15) & _chr_set[x & 1][y & 1]) ? ((i >> 4) & 7) + 1 : 0 : -1;
}







