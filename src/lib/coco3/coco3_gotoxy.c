
#include "_coco3.h"

asm void coco3_gotoxy(int x, int y)
{
    asm {
        lda     3,s
        ldb     5,s
        pshs    u,y                             // protect against BASIC routine
        jsr     $f8f7                           // inside the LOCATE command
        puls    y,u
    }
}

