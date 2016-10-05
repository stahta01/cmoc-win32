
#include "_coco3.h"

asm coco3_data_t* coco3_data_enter(void)
{
    asm {
        bsr     $f772
        ldd     #$fe00
    }
}

