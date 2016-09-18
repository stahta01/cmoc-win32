
#include <string.h>
#include <stdio.h>
#include <equates.h>
#include <float.h>

#pragma options -machine=coco

#define _FPA3 _V40
#define _FPA4 _V45



#define M_2PI (*(float_t*)_LBFBD)

void asm _setfpa0(float_t* f)
{
    asm {
        ldx     2,s
        jsr     _LBC14
    }
}

void asm _fpa0tofpa1(void)
{
    asm {
        jsr     _LBC4A
    }
}

void asm _atof(float_t* dst, char* str)
{
    asm {
        pshs    u
        ldx     6,s
        leax    -1,x
        stx     _CHARAD
        jsr     _GETNCH
        //sec
        jsr     _LBD12
        puls    u
    }
}


int main(void)
{
    float_t a, b;

    //_atof(&a, "-1234");

    _itof(&a, -100);

    printf("%d\n", _ftoi(&a));
    //printf("%d\n", _ftoi((float_t*)_FPA3));

    //printf("%d\n", _ftoi(&M_2PI));

    return 0;
}

