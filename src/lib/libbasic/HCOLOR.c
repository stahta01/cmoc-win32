
#include <basic.h>
#include <cmoc.h>

void HCOLOR(int c1, int c2)
{
    if ((_get_ostype & 7) == CMOC_MAC_COCO3) {
        systemf("HCOLOR %d,%d", c1, c2);
    }
}

