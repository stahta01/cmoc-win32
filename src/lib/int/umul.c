
#include "_int.h"

// Multiply D by X, unsigned; return result in D; preserve X.

asm word _umul(word v1, word v2)
{
    asm {
        ldd     2,s
        ldx     4,s

        MUL16: export
        MUL16:

        pshs    u,x,b,a                             // U pushed to create 2 temp bytes at 4,S
        ldb     3,s                                 // low byte of original X
        mul
        std     4,s                                 // keep for later
        ldd     1,s                                 // low byte of orig D, high byte of orig X
        mul
        addb    5,s                                 // only low byte is needed
        stb     5,s
        lda     1,s                                 // low byte of orig D
        ldb     3,s                                 // low byte of orig X
        mul
        adda    5,s
        leas    6,s
    }
}

