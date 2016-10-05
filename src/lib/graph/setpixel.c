
#include "_graph.h"

void _setpixel(int x, int y)
{
    if (_pmode & 1) {
        _setpixel2(x, y, _forcol);
    } else {
        _setpixel1(x, y, _forcol);
    }
}

