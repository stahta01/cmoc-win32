
#include "_memory.h"

asm void* memlsl(void* dst, size_t size)
{
    asm {
        ldd     4,s                             // get size
        beq     exit                            // exit if zero
        tfr     d,y                             // y = size
        ldx     2,s                             // x = dst
        leax    d,x                             // offset by size
        lsl     ,-x                             // lsl first byte
        dey                                     // decrease size
        beq     exit                            // exit if done
        loop:
        rol     ,-x                             // rol next byte
        dey                                     // decrease size
        bne     loop                            // loop if not done
        exit:
        ldd     2,s                             // return dst
    }
}

