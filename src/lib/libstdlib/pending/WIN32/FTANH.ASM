;-----------------------------------------------------------------------------
; __ftanh() - floating point hyperbolic tangeent
;-----------------------------------------------------------------------------
                .386
_TEXT           segment use32 para public 'CODE';Start of main code segment
                public  __ftanh                 ;Make public for all
__ftanh         proc    near                    ;Floating point hyp tangeent
                assume  cs:_TEXT                ;Set default code segment
                push    ebp                     ;Save register bp
                mov     ebp,esp                 ;Point to the stack frame
                fld     qword ptr [ebp+8]       ;Load real from stack
                fld     st                      ;Duplicate stack top
                fadd                            ;Compute 2 * x
                fldl2e                          ;Load log base 2(e)
                fmulp   st(1),st                ;Multiply x * log base 2(e)
                fst     st(1)                   ;Push result
                frndint                         ;Round to integer
                fsub    st(1),st                ;Subtract
                fxch                            ;Exchange st, st(1)
                f2xm1                           ;Compute 2 to the (x - 1)
                fld1                            ;Load real number 1
                fadd                            ;2 to the x
                fscale                          ;Scale by power of 2
                fstp    st(1)                   ;Set new stack top and pop
                fld1                            ;Load constant 1
                fadd                            ;Compute exp(2*x)+1
                fld1                            ;Load the constant 1
                fld1                            ;Load the constant 1
                fadd                            ;Set divisor to 2
                fdivr                           ;Compute 2/(exp(2*x)+1)
                fld1                            ;Load constant 1
                fsubr                           ;Compute the hyperbolic tangent
                pop     ebp                     ;Restore register bp
                ret                             ;Return to caller
__ftanh         endp                            ;End of procedure
_TEXT           ends                            ;End of segment
                end                             ;End of module
