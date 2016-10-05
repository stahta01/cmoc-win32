
#include "_coco3.h"

void coco3_wherexy(point_t* point)
{
    coco3_data_t* data = coco3_data_enter();
    point->x = data->cursx;
    point->y = data->cursy;
    coco3_data_leave();
}

