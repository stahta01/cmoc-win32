
#include "_memory.h"

asm void* memrol(void* dst, int val, size_t size)
{
    asm {
        ldd     6,s                                 // get size
        beq     exit                                // exit if zero
        tfr     d,y                                 // y = size
        ldx     2,s                                 // x = dst
        leax    d,x                                 // offset by size
        rol     5,s                                 // get cc from val byte
        loop:
        rol     ,-x                                 // rol next byte
        dey                                         // decrease size
        bne     loop                                // loop if not done
        exit:
        ldd     2,s                                 // return dst
    }
}

