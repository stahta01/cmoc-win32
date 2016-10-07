
// By Pierre Sarrazin <http://sarrazip.com/>.
// This file is in the public domain.
//
// Converted to C for WinCMOC by Derek Evans 2016

#include "_cmoc.h"

asm void zerodw(word* dw)
{
    asm {
        ldx     2,s                             // load dw to point to double word
        clra
        clrb
        std     ,x
        std     2,x
    }
}

