
#include <basic.h>
#include <graph.h>

void MCIRCLE(int x, int y, int r, byte c)
{
    _setcolor(c);
    _arc(x, y, r, r, 0, 256);
}

