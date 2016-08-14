;-----------------------------------------------------------------------------
; __fexp() - floating point exponent
;-----------------------------------------------------------------------------
                .386
_TEXT           segment use32 para public 'CODE';Start of main code segment
                public  __fexp                  ;Make public for all
__fexp          proc    near                    ;Floating point exponent
                assume  cs:_TEXT                ;Set default code segment
                push    ebp                     ;Save register bp
                mov     ebp,esp                 ;Point to the stack frame
                sub     esp,8                   ;Allocate temporary space
                fld     qword ptr [ebp+8]       ;Load real from stack
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
                fst     qword ptr [ebp-8]       ;Throw away scale factor
                mov     esp,ebp                 ;Deallocate temporary space
                pop     ebp                     ;Restore register bp
                ret                             ;Return to caller
__fexp          endp                            ;End of procedure
_TEXT           ends                            ;End of segment
                end                             ;End of module
