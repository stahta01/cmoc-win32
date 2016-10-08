
#include "_memory.h"

asm void* memlsl(void* dst, size_t size)
{
    asm {
        ldy     4,s                                 // y = size
        beq     return                              // return if zero
        tfr     y,d                                 // d = y
        ldx     2,s                                 // x = dst
        leax    d,x                                 // offset x by size
        lsl     ,-x                                 // lsl first byte
        dey                                         // decrease size
        beq     return                              // return if done
        repeat:
        rol     ,-x                                 // rol next byte
        dey                                         // decrease size
        bne     repeat                              // repeat if not done
        return:
        ldd     2,s                                 // return dst
    }
}

