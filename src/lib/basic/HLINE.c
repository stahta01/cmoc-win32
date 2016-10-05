
#include <basic.h>

void __HLINE(int x1, int y1, int x2, int y2, char* mode, char* type)
{
    systemf("HLINE(%d,%d)-(%d,%d)%s%s", x1, y1, x2, y2, mode, type);
}

void HLINE(int x1, int y1, int x2, int y2, int onoff)
{
    __HLINE(x1, y1, x2, y2, onoff ? ",PSET" : ",PRESET", "");
}

void HLINE_B(int x1, int y1, int x2, int y2, int onoff)
{
    __HLINE(x1, y1, x2, y2, onoff ? ",PSET" : ",PRESET", ",B");
}

void HLINE_BF(int x1, int y1, int x2, int y2, int onoff)
{
    __HLINE(x1, y1, x2, y2, onoff ? ",PSET" : ",PRESET", ",BF");
}

