
#include "_graph.h"

void _setpixel(int x, int y)
{
    if (_pmode & 1) {
        _setpixel2(x, y, _graph.color);
    } else {
        _setpixel1(x, y, _graph.color);
    }
}

int _getpixel(int x, int y)
{
    return _pmode & 1  ? _getpixel2(x, y) : _getpixel1(x, y);
}




