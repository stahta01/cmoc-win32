
#include "_long.h"

asm long_t* _CNAME(long_t* dst, long_t* slx, long_t* sly)
{
    asm {
        ldx     6,s                             // load x with pointer to sly
        ldy     4,s                             // load y with pointer to slx
        ldd     0,y                             // load d,y with src2
        ldy     2,y
        pshs    d,y                             // push slx onto the stack
        bsr     _ANAME                          // returns x pointing to result
        ldy     2,s                             // load y with pointer to dst
        ldd     0,x                             // copy 4 bytes from x to y
        std     0,y
        ldd     2,x
        std     2,y
        tfr     y,d                             // return result pointer in d
    }
}

