
#include "_coco3.h"

void coco3_screensize(int* x, int* y)
{
    coco3_data_t* data = coco3_data_enter();
    *x = data->column;
    *y = data->row;
    coco3_data_leave();
}

