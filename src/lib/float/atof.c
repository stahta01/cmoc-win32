
#include "_float.h"

asm float_t* _atof(char* src, float_t* dst)
{
    asm {
        pshs    u
        ldx     4,s
        leax    -1,x
        stx     _CHARAD
        jsr     _GETNCH                         // GET A CHARACTER FROM BASIC
        jsr     _LBD12                          // CONVERT ASCII STRING TO FLOATING POINT
        ldx     6,s
        jsr     _LBC35                          // PACK FPA0 AND MOVE IT TO ADDRESS IN X
        puls    u
        ldd     4,s
    }
}

