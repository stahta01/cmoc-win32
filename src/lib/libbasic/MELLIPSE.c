
#include <basic.h>
#include <graph.h>

void MELLIPSE(int x, int y, int w, int h, byte c)
{
    _setcolor(c);
    _arc(x, y, w, h, 0, 256);
}

