
#include "_memory.h"

asm void* memcpy16(void* dst, void* src, size_t size)
{
    asm {
        ldd     6,s
        beq     return
        lsld
        lsld
        lsld
        lsld
        addd    #7
        addd    2,s
        std     _V42
        sei
        pshs    u,dp
        sts     _V40
        ldu     5,s
        leau    7,u
        lds     7,s

        repeat:
        puls    x,y,d,dp
        pshu    x,y,d,dp
        leau    14,u
        puls    x,y,d,dp
        pshu    x,y,d,dp
        leau    16,u
        ldd     ,s++
        std     -9,u
        cmpu    _V42
        bne     repeat
        lds     _V40
        puls    u,dp
        cli
        return:
        ldd     2,s
    }
}

