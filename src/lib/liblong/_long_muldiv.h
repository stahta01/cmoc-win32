
#include "_long.h"

asm long_t* _CNAME(long_t* dst, long_t* src1, long_t* src2)
{
    asm {
        ldx     4,s                             // load x with pointer to src1
        ldy     6,s                             // load y with pointer to src2
        ldd     0,y                             // load d,y with src2
        ldy     2,y
        pshs    d,y                             // push src2 onto the stack
        bsr     _ANAME                          // returns x pointing to result
        ldy     2,s                             // load y with pointer to dst
        ldd     0,x                             // copy 4 bytes from x to y
        std     0,y
        ldd     2,x
        std     2,y
        tfr     y,d                             // return result pointer in d
    }
}
#define y pcr
#include "../kreiderclib/_kreider.h"

