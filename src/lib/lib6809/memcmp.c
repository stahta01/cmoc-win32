
#define _NAME memcmp
#define _FILE "kreider/LIB/LIB.A/memcmp.a"
#include "_kreider.h"

/*
// By Pierre Sarrazin <http://sarrazip.com/>.
// This file is in the public domain.
//
// Converted to C for WinCMOC by Derek Evans 2016

// Returns 0, 1 or $FF in B. Leaves A undefined.

int asm memcmp(void* s1, void* s2, unsigned n)
{
    asm {
        pshs    u,y
        ldy     10,s            // number of bytes to compare
        beq     memcmp_equal
        ldx     6,s             // 1st string
        ldu     8,s             // 2nd string

        memcmp_loop:
        lda     ,x+             // byte from 1st string
        cmpa    ,u+             // compare with byte from 2nd
        bne     memcmp_diff     // if bytes different

        leay    -1,y            // one byte done
        bne     memcmp_loop     // if more to do

        memcmp_equal:
        clrb                    // return 0: regions are equal
        bra     memcmp_end

        memcmp_diff:
        cmpa    -1,u
        bhi     memcmp_ret1     // return +1: 1st string comes after

        ldb     #$FF            // return -1: 1st string comes before
        bra     memcmp_end

        memcmp_ret1:
        ldb     #1

        memcmp_end:
        sex                     // return int
        puls    y,u,pc

    }
}
*/



