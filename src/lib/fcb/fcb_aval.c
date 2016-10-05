
#include "_fcb.h"

int fcb_aval(void)
{
    int index;
    for (index = fcb_act(); index-- > 0;) {
        if (!fcb_get(index)->typ) {
            break;
        }
    }
    return index;
}

