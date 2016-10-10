
#include "_memory.h"

asm void* memrol1(void* dst, int val, size_t size)
{
    asm {
        ldy     6,s                                 // y = size
        beq     return                              // exit if zero
        tfr     y,d                                 // d = y
        ldx     2,s                                 // x = dst
        leax    d,x                                 // offset x by size
        rol     5,s                                 // get cc from val byte
        repeat:
        rol     ,-x                                 // rol next byte
        dey                                         // decrease size
        bne     repeat                              // repeat if not done
        return:
        ldd     2,s                                 // return dst
    }
}

