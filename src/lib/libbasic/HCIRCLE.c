
#include <basic.h>
#include <cmoc.h>

void HCIRCLE(int x, int y, int r)
{
    if ((_get_ostype & 7) == CMOC_MAC_COCO3) {
        systemf("HCIRCLE (%d,%d),%d", x, y, r);
    }
}

