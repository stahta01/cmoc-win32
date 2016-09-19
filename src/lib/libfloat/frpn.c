
#include "_float.h"

float_t* _vfrpn(float_t* dst, va_list args)
{
    while (*args) {
        switch (*args++) {
        case 'd':
            asm {
                ldd     [args]
                jsr     _GIVABF
            }
            args++;
            break;
        case 'f':
            asm {
                ldx     [args]
                jsr     _LBC14                  // COPY A PACKED FP NUMBER FROM (X) TO FPA0
            }
            args++;
            break;
        case 's':
            asm {
                ldx     [args]
                leax    -1,x
                stx     _CHARAD
                pshs    u
                jsr     _GETNCH                 // GET A CHARACTER FROM BASIC
                jsr     _LBD12                  // CONVERT ASCII STRING TO FLOATING POINT
                puls    u
            }
            args++;
            break;
        default:
            asm {
                puls    x,y,d
                std     _FP1EXP
                stx     _FP1EXP+2
                sty     _FP1EXP+4
                puls    x,y,d
                std     _FP0EXP
                stx     _FP0EXP+2
                sty     _FP0EXP+4
            }
            switch (args[-1]) {
            case '-':
                asm {
                    com     _FP1SGN
                }
            case '+':
                asm {
                    // Compute sign of result.
                    ldb     _FP0SGN
                    eorb    _FP1SGN
                    stb     _RESSGN
                    pshs    u
                    lda     $5C                 // load exponent of FPA1
                    ldb     $4F                 // load exponent of FPA0
                    jsr     _LB9C5
                    puls    u
                }
                break;
            case '*':
                asm {
                    // Compute sign of result, as in $BB2F.
                    ldb     _FP0SGN
                    eorb    _FP1SGN
                    stb     _RESSGN
                    pshs    u
                    lda     _FP1EXP
                    ldb     _FP0EXP             // as in $BB2F; sets N and Z
                    jsr     $BACC               // starts with BEQ instruction
                    puls    u
                }
                break;
            case '/':
                asm {
                    // Compute sign of result.
                    ldb     _FP0SGN
                    eorb    _FP1SGN
                    stb     _RESSGN
                    pshs    u
                    lda     _FP1EXP
                    ldb     _FP0EXP             // as in $BB2F; sets N and Z
                    jsr     _LBB91              // starts with BEQ instruction
                    puls    u
                }
                break;
            default:
                return 0;
            }
        }
        asm {
            ldd     _FP0EXP
            ldx     _FP0EXP+2
            ldy     _FP0EXP+4
            pshs    x,y,d
        }
    }
    asm {
        pshs    u
        ldx     dst
        jsr     _LBC35                          // PACK FPA0 AND MOVE IT TO ADDRESS IN X
        puls    u
    }
    return dst;
}

float_t* _frpn(float_t* dst, ...)
{
    va_list args;
    va_start(args, dst);
    float_t* result = _vfrpn(dst, args);
    va_end();
    return result;
}

