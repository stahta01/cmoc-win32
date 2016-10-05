
#include "_coco.h"

// May be called more than once.
//
void initCoCoSupport()
{
    word irqServiceRoutineAddress = * (word*) 0xFFF8;
    isCoCo3 = (irqServiceRoutineAddress == 0xFEF7);
}

