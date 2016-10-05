
#include "_coco3.h"

int coco3_wherey(void)
{
    int result = coco3_data_enter()->cursy;
    coco3_data_leave();
    return result;
}

