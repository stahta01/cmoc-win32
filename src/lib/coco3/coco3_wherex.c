
#include "_coco3.h"

int coco3_wherex(void)
{
    int result = coco3_data_enter()->cursx;
    coco3_data_leave();
    return result;
}

