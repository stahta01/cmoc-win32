
#include "_coco.h"

void _setHighSpeed(byte fast)
{
    asm {
        ldx     #65494
        tst     fast
        beq     setHighSpeed_010
        leax    1,x
        setHighSpeed_010:
        tst     isCoCo3
        beq     setHighSpeed_020
        leax    2,x
        setHighSpeed_020:
        clr     ,x
    }
}

