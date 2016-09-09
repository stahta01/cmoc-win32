
#include "_graph.h"

void _lineto(int x, int y)
{
    _line(_graph.curx, _graph.cury, x, y);
    _graph.curx = x;
    _graph.cury = y;
}

