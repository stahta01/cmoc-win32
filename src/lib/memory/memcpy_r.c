
#include "_memory.h"

asm void* memcpy_r(void* dst, void* src, size_t size)
{
    asm {
        ldy     6,s                                 // y = size
        beq     return                              // return if zero
        tfr     y,d                                 // d = y
        ldx     4,s                                 // x = src
        leax    d,x                                 // offset x by size
        pshs    u                                   // save u
        ldu     4,s                                 // u = dst
        leau    d,u                                 // offset u by size
        andb    #1                                  // check for even size
        beq     repeat                              // if even then we can copy 2 bytes at a time
        lda     ,-x                                 // copy one byte to make size even
        sta     ,-u
        leay    -1,y                                // decrease counter
        beq     break                               // break if only one byte
        repeat:
        ldd     ,--x                                // copy two bytes
        std     ,--u
        leay    -2,y                                // decrease counter
        bne     repeat                              // repeat until size = 0
        break:
        puls    u                                   // restore u
        return:
        ldd     2,s                                 // return dst
    }
}

