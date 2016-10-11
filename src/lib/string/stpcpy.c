
#include "_string.h"

asm char* stpcpy(char* dst, char* src)
{
    asm {
        ldx     2,s                                 // x = dst
        ldy     4,s                                 // y = src
        repeat:
        lda     ,y+                                 // copy byte
        sta     ,x+
        bne     repeat                              // repeat until done
        dex                                         // back up one
        tfr     x,d                                 // return ptr to null
    }
}

/*
char* stpcpy(char* dst, char* src)
{
    for (; *src; *dst++ = *src++);
    *dst = 0;
    return dst;
}
*/

