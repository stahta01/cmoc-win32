
// Contributed by Brian K. Holman (me@brianholman.com)
// Based on information provided by Pierre Sarrazin <http://sarrazip.com/>
// Many thanks, Derek :-)

#include "_float.h"

asm float_t* _fsin(float_t* dst, float_t* src)
{
    asm {
        ldy     #_SIN
        jmp     _fruny2
        /*
        pshs    u
        ldx     6,s
        jsr     _LBC14                          // COPY A PACKED FP NUMBER FROM (X) TO FPA0
        jsr     $BF78                           // CALL BASIC SIN FPA0
        ldx     4,s
        jsr     _LBC35                          // PACK FPA0 AND MOVE IT TO ADDRESS IN X
        puls    u
        ldd     2,s
        */
    }
}

