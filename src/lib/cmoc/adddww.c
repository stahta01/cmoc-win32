
// By Pierre Sarrazin <http://sarrazip.com/>.
// This file is in the public domain.
//
// Converted to C for WinCMOC by Derek Evans 2016

#include "_cmoc.h"

// Adds the 16-bit integer 'term' to the 32-bit integer designated by
// twoWords[0] and twoWords[1].

asm void adddww(word* dw, word w)
{
    asm {
        pshs    u
        tfr     s,u
        ldx     4,u                             // load dw to point to double word
        ldd     2,x                             // low word of dword
        addd    6,u                             // add w: affects carry flag
        std     2,x                             // store low word of result (does not affect carry flag)
        ldd     ,x                              // load high word of dword (does not affect carry flag)
        adcb    #0                              // add possible carry from add of low word with w
        adca    #0                              // add possible carry from adcb
        std     ,x
        tfr     u,s
        puls    u,pc
    }
}

