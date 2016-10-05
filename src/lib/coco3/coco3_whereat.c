
#include "_coco3.h"

int coco3_whereat(void)
{
    int result = (coco3_data_enter()->crsloc - 0x2000) >> 1;
    coco3_data_leave();
    return result;
}

