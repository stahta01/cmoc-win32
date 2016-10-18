
#include "_coco.h"

// Show the text mode.
//
asm void _showPmode0()
{
    asm {
        ldb     $FF22
        andb    #7
        stb     $FF22
    }
}

