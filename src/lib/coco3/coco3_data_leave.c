
#include "_coco3.h"

asm void coco3_data_leave(void)
{
    asm {
        bsr    $F778
    }
}

