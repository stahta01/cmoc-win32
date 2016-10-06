
#include "_memory.h"

asm void* _memrcpy(void* dst, void* src, size_t size)
{
    asm {
        ldd     6,s                             // get size
        beq     exit                            // exit if zero
        pshs    u                               // save u
        tfr     s,x                             // save s in x
        ldu     4,s                             // u = dst
        leau    d,u                             // offset by size
        lds     6,s                             // s = src
        leas    d,s                             // offset by size
        tfr     d,y                             // y = size
        loop:
        lda     ,-s                             // copy one byte
        sta     ,-u
        leay    -1,y                            // decrease size
        bne     loop                            // loop until size = 0
        tfr     x,s                             // restore s
        puls    u                               // restore u
        exit:
        ldd     2,s                             // return dst
    }
}

