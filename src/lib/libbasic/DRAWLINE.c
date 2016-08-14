
#include <basic.h>
#include <stdlib.h>

void DRAWLINE(int x1, int y1, int x2, int y2, byte c)
{
    x2 -= x1;
    y2 -= y1;
    int x = _abs(x2), y = _abs(y2), i = _max(x, y);
    if (i > 0) {
        ((byte*)&x1)[0] = ((byte*)&x1)[1];
        ((byte*)&y1)[0] = ((byte*)&y1)[1];
        ((byte*)&x2)[0] = ((byte*)&x2)[1];
        ((byte*)&y2)[0] = ((byte*)&y2)[1];
        ((byte*)&x1)[1] = ((byte*)&y1)[1] = ((byte*)&x2)[1] = ((byte*)&y2)[1] = 0;
        x2 /= i;
        y2 /= i;
        while (i-- >= 0) {
            SET(*(byte*)&x1, *(byte*)&y1, c);
            x1 += x2;
            y1 += y2;
        }
    }
}








