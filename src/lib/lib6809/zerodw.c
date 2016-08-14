
// CMOC's standard library functions.
//
// By Pierre Sarrazin <http://sarrazip.com/>.
// This file is in the public domain.

#include <cmoc.h>

void asm zerodw(word* dw)
{
    asm {
        ldx     2,s     // load dw to point to double word
        clra
        clrb
        std     ,x
        std     2,x
    }
}


