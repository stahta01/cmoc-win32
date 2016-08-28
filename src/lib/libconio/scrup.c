
#include "_conio.h"

void asm memcpy_fast(void* dst, void* src, size_t len)
{
    asm {
        ldx     2,s             // dst
        ldy     4,s             // src
        ldd     6,s             // len

        memcpy_dispatch:

        memcpy_dispatch11:
        cmpd    #11
        bhi     memcpy_copyx
        blo     memcpy_dispatch9

        memcpy_copy11:
        lda     10,y
        sta     10,x
        memcpy_copy10:
        ldd     8,y
        std     8,x
        ldd     6,y
        std     6,x
        ldd     4,y
        std     4,x
        ldd     2,y
        std     2,x
        ldd     0,y
        std     0,x
        rts

        memcpy_copyx:
        pshs    dp,u
        sts     _TEMPTR
        leau    5,x
        leas    ,y
        subd    #10

        memcpy_copyx_loop:
        puls    x,y,dp
        pshu    x,y,dp
        leau    10,u
        puls    x,y,dp
        pshu    x,y,dp
        leau    10,u
        subd    #10
        bpl     memcpy_copyx_loop
        leax    -5,u
        leay    0,s
        lds     _TEMPTR
        puls    dp,u
        addd    #10
        bra     memcpy_dispatch

        memcpy_dispatch9:
        cmpd    #9
        bhi     memcpy_copy10
        blo     memcpy_dispatch7

        memcpy_copy9:
        lda     8,y
        sta     8,x
        memcpy_copy8:
        ldd     6,y
        std     6,x
        ldd     4,y
        std     4,x
        ldd     2,y
        std     2,x
        ldd     0,y
        std     0,x
        rts

        memcpy_dispatch7:
        cmpd    #7
        bhi     memcpy_copy8
        blo     memcpy_dispatch5

        memcpy_copy7:
        lda     6,y
        sta     6,x
        memcpy_copy6:
        ldd     4,y
        std     4,x
        ldd     2,y
        std     2,x
        ldd     0,y
        std     0,x
        rts

        memcpy_dispatch5:
        cmpd    #5
        bhi     memcpy_copy6
        blo     memcpy_dispatch3

        memcpy_copy5:
        lda     4,y
        sta     4,x
        memcpy_copy4:
        ldd     2,y
        std     2,x
        ldd     0,y
        std     0,x
        rts

        memcpy_dispatch3:
        cmpd    #3
        bhi     memcpy_copy4
        blo     memcpy_dispatch1

        memcpy_copy3:
        lda     2,y
        sta     2,x
        memcpy_copy2:
        ldd     0,y
        std     0,x
        rts

        memcpy_dispatch1:
        cmpd    #1
        bhi     memcpy_copy2
        blo     memcpy_copy0

        memcpy_copy1:
        lda     0,y
        sta     0,x

        memcpy_copy0:
    }
}

void scrup(void)
{
    if (isvidram()) {
        memcpy_fast(_VIDRAM, _VIDRAM + 32, 32 * 15);
        memset(_VIDRAM + 32 * 15, 96, 32);
    } else {
        if (isgrpram()) {
            unsigned line = (unsigned)_horbyt << 3;
            memcpy_fast((void*)_beggrp, (void*)(_beggrp + line), (_endgrp - _beggrp) - line);
            memset((void*)(_endgrp - line), _conio.bgcolor ? 255 : 0, line);
        }
    }
}

