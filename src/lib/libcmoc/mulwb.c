
// By Pierre Sarrazin <http://sarrazip.com/>.
// This file is in the public domain.
//
// Converted to C for WinCMOC by Derek Evans 2016

#include <cmoc.h>

/*
* Multiples w by b to obtain a 24-bit product.
* Stores the high byte of the product in *productHi,
* and returns the low word of the product.
*/
word asm mulwb(byte* productHi, word w, byte b)
{
    asm {
        pshs    u
        tfr     s,u
        ldx     6,u                     // load w
        ldb     9,u                     // load b
        bsr     MUL168_TO24
        pshs    x                       // preserve low word of product
        ldx     4,u                     // get productHi pointer
        stb     ,x                      // return high byte of product
        puls    a,b                     // retrieve and return low word of product
        tfr     u,s
        puls    u,pc

        //MUL168_TO24: EXPORT

        MUL168_TO24:
        pshs    x,b,a
        clr     ,-s                     // allocate 3 bytes to store 24-bit product
        clr     ,-s
        clr     ,-s
        lda     6,s                     // low byte of X
        mul
        std     1,s                     // low 16-bit of 24-bit storage
        ldd     4,s                     // original B in A, high byte of X in B
        mul
        addd    ,s                      // add D to high 16 bits of storage
        std     ,s
        ldb     ,s
        ldx     1,s
        lda     3,s                     // restore orignal A
        leas    7,s
    }
}

