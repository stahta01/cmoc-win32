
// By Pierre Sarrazin <http://sarrazip.com/>.
// This file is in the public domain.
//
// Converted to C for WinCMOC by Derek Evans 2016

#include <cmoc.h>

// byte sub32(word *hi, word h, word l)
// Subtracts 32-bit integer h:l from 32-bit unsigned integer
// pointed by 'hi'.
// Returns carry of the subtraction.

byte asm sub32(word* hi, word h, word l)
{
    asm {
        pshs    U
        tfr     S,U
        leas    -1,S
        pshs    x,b
        pshs    u
        ldx     4,U         // variable hi
        leau    6,U         // variable h
        bsr     SUB32
        puls    u
        tfr     cc,b
        andb    #1
        stb     -1,U        // variable carry
        puls    b,x
        ldb     -1,U        // variable carry
        tfr     U,S
        puls    U,PC

// Subtract 32-bit unsigned integer from another.
// In: X => first integer, U => second integer.
// Out: first minus second in space pointed by X,
//      carry bit reflects subtraction.
// Preserves: all, except CC

        SUB32:
        pshs    b,a

        ldd     2,x         // low word of first
        subd    2,u         // low word of second
        pshs    cc          // preserve carry bit
        std     2,x         // store in low word of first

        ldd     ,x          // high word of first
        puls    cc          // restore carry bit from 1st sub
        sbcb    1,u
        sbca    ,u
        pshs    cc          // preserve carry bit
        std     ,x
        puls    cc          // restore carry bit from last sub

        puls    a,b,pc      // carry bit from last sub returned
    }
}


