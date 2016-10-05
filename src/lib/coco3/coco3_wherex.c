
#include "_coco3.h"

int coco3_wherex(void)
{
    coco3_data_t* data = coco3_data_enter();
    int result = data->cursx;
    coco3_data_leave();
    return result;
}

