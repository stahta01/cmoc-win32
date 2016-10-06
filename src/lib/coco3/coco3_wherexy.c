
#include "_coco3.h"

void coco3_wherexy(int* x, int* y)
{
    coco3_data_t* data = coco3_data_enter();
    *x = data->cursx;
    *y = data->cursy;
    coco3_data_leave();
}

