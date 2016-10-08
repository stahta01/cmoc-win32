
#include "_memory.h"

asm void* memcpy_r(void* dst, void* src, size_t size)
{
    asm {
        ldd     6,s                             // get size
        beq     done                            // exit if zero
        tfr     d,y                             // y is our counter
        ldx     4,s                             // x = src
        leax    d,x
        pshs    u                               // save u
        ldu     4,s                             // u = dst
        leau    d,u
        andb    #1                              // check for even size
        beq     loop                            // if even then we can copy 2 bytes at a time
        lda     ,-x                             // copy one byte to make size even
        sta     ,-u
        leay    -1,y                            // decrease counter
        beq     endloop                         // exit if only one byte
        loop:
        ldd     ,--x                            // copy one byte
        std     ,--u
        leay    -2,y                            // decrease counter
        bne     loop                            // loop until size = 0
        endloop:
        puls    u                               // restore u
        done:
        ldd     2,s                             // return dst
    }
}

