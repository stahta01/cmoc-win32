
#include <basic.h>
#include <cmoc.h>

void HSCREEN(int mode)
{
    if ((_get_ostype & 7) == CMOC_MAC_COCO3) {
        systemf("HSCREEN %d", mode);
    }
}

