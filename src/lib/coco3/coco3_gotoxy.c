
#include "_coco3.h"

void coco3_gotoxy(int x, int y)
{
    coco3_data_t* data = coco3_data_enter();
    data->cursx = (byte)x;
    data->cursy = (byte)y;
    data->crsloc = 0x2000 + (x << 1) + y * data->column;
    coco3_data_leave();
}

