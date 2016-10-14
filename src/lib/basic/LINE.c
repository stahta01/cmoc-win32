
#include "_basic.h"

void __LINE(int x1, int y1, int x2, int y2, char* mode, char* type)
{
    systemf("LINE(%d,%d)-(%d,%d)%s%s", x1, y1, x2, y2, mode, type);
}

void LINE(int x1, int y1, int x2, int y2, int onoff)
{
    __LINE(x1, y1, x2, y2, onoff ? ",PSET" : ",PRESET", "");
}

void LINE_B(int x1, int y1, int x2, int y2, int onoff)
{
    __LINE(x1, y1, x2, y2, onoff ? ",PSET" : ",PRESET", ",B");
}

void LINE_BF(int x1, int y1, int x2, int y2, int onoff)
{
    __LINE(x1, y1, x2, y2, onoff ? ",PSET" : ",PRESET", ",BF");
}

