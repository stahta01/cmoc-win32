
#include "_memory.h"

/*
void memxor(void* ptr, char value, size_t n)
{
    asm {
        ldx     ptr
        beq     exit$
        ldy     n
        beq     exit$
        ldb     value
        loop$:
        tfr     b,a
        eora    ,x
        sta     ,x+
        leay    -1,y
        bne     loop$
        exit$:
    }
}
*/

void* memxor(void* ptr, int value, size_t n)
{
    for (char* p = (char*)ptr, *e = p + n; p < e; p++) {
        *p ^= (char)value;
    }
    return ptr;
}

