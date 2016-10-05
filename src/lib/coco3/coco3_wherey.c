
#include "_coco3.h"

int coco3_wherey(void)
{
    coco3_data_t* data = coco3_data_enter();
    int result = data->cursy;
    coco3_data_leave();
    return result;
}

