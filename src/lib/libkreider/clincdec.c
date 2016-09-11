
void asm __libkreider(void)
{
    asm {
        _linc:
        ldx     2,s
        bra     linc
        _ldec:
        ldx     2,s
        bra     ldec
#define psect *
#define endsect *
#define _linc linc
#define _ldec ldec
#include "clib/LIB/IMATH/clincdec.a"
    }
}

