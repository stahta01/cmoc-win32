
#include "_coco3.h"

void coco3_gotox(int x)
{
    coco3_data_t* data = coco3_data_enter();
    data->cursx = (byte)x;
    data->crsloc = 0x2000 + (((word)data->column * data->cursy + x) << 1);
    coco3_data_leave();
}

