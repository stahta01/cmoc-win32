
#include "_graph.h"

void _setcliprgn(int x1, int y1, int x2, int y2)
{
    _graph.clipx1 = x1;
    _graph.clipy1 = y1;
    _graph.clipx2 = x2;
    _graph.clipy2 = y2;
}

