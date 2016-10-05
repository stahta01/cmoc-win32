
#include "_coco3.h"

void coco3_gotoy(int y)
{
    coco3_data_t* data = coco3_data_enter();
    data->cursy = (byte)y;
    data->crsloc = 0x2000 + (((word)data->column * y + data->cursx) << 1);
    coco3_data_leave();
}

