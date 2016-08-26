
#include <basic.h>

int _system();

void PAINT(int x, int y, byte c, byte b)
{
    sprintf(_linbuf + 1, "PAINT(%d,%d),%d,%d", x, y, c, b);
    _system();
}

