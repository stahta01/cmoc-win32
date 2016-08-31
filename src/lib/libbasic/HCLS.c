
#include <basic.h>
#include <cmoc.h>

void HCLS(int c)
{
    if ((_get_ostype & 7) == CMOC_MAC_COCO3) {
        systemf("HCLS %d", c);
    }
}

