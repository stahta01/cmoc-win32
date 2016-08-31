
#include <basic.h>
#include <cmoc.h>

void HPAINT(int x, int y, int c, int b)
{
    if ((_get_ostype & 7) == CMOC_MAC_COCO3) {
        systemf("HPAINT (%d,%d),%d,%d", x, y, c, b);
    }
}

