
#include "_coco.h"

// Show the text mode.
//
void asm showPmode0()
{
    asm {
        ldb     $FF22
        andb    #7
        stb     $FF22
    }
}



