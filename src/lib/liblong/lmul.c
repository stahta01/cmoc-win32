
#include "_long.h"

asm long_t* _lmul(long_t* dst, long_t* src1, long_t* src2)
{
    asm {
        ldx     4,s
        ldy     6,s
        ldd     0,y
        ldy     2,y
        pshs    d,y
        bsr     lmul
        ldy     2,s
        ldd     ,x
        std     ,y
        ldd     2,x
        std     2,y
        tfr     y,d
    }
}
#define y pcr
#define _FILE  "clmul.as"
#include "../src/lib/kreiderclib/_kreider.h"

