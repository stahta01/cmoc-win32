;-----------------------------------------------------------------------------
; __flog() - floating point logarithm
;-----------------------------------------------------------------------------
                .386
_TEXT           segment use32 para public 'CODE';Start of main code segment
                public  __flog                  ;Make public for all
__flog          proc    near                    ;Floating point logarithm
                assume  cs:_TEXT                ;Set default code segment
                push    ebp                     ;Save register bp
                mov     ebp,esp                 ;Point to the stack frame
                fld     qword ptr [ebp+8]       ;Load real from stack
                fldln2                          ;Load log base e of 2
                fxch    st(1)                   ;Exchange st, st(1)
                fyl2x                           ;Compute the natural log(x)
                pop     ebp                     ;Restore register bp
                ret                             ;Return to caller
__flog          endp                            ;End of procedure
_TEXT           ends                            ;End of segment
                end                             ;End of module
