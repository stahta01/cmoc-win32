
#include "_coco.h"

// Writes the given byte in the 6k PMODE 4 screen buffer (0x1800 bytes long)
// starting at the address given by 'textScreenBuffer'.
//
void pcls(byte* buffer, byte byteToClearWith)
{
    word* end = (word*)(buffer + 0x1800);

    asm {
        lda     byteToClearWith
        tfr     a,b
        ldx     buffer
        pcls_loop:
        std     ,x++
        std     ,x++
        std     ,x++
        std     ,x++
        std     ,x++
        std     ,x++
        std     ,x++
        std     ,x++
        std     ,x++
        std     ,x++
        std     ,x++
        std     ,x++
        std     ,x++
        std     ,x++
        std     ,x++
        std     ,x++
        cmpx    end
        bne     pcls_loop
    }
}

