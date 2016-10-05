
#include "_coco3.h"

void coco3_gotoy(int y)
{
    coco3_data_t* data = coco3_data_enter();
    data->cursy = (byte)y;
    data->crsloc = 0x2000 + (data->cursx << 1) + y * data->column;
    coco3_data_leave();
}

