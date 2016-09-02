
#include "_graph.h"

int _getpixel(int x, int y)
{
    return _pmode & 1  ? _getpixel2(x, y) : _getpixel1(x, y);
}

