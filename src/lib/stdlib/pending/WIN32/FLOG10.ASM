;-----------------------------------------------------------------------------
; __flog10() - floating point logarithm base 10
;-----------------------------------------------------------------------------
                .386
_TEXT           segment use32 para public 'CODE';Start of main code segment
                public  __flog10                ;Make public for all
__flog10        proc    near                    ;Floating point log base 10
                assume  cs:_TEXT                ;Set default code segment
                push    ebp                     ;Save register bp
                mov     ebp,esp                 ;Point to the stack frame
                fld     qword ptr [ebp+8]       ;Load real from stack
                fldlg2                          ;Load log base 10 of 2
                fxch    st(1)                   ;Exchange st, st(1)
                fyl2x                           ;Compute the log base 10(x)
                pop     ebp                     ;Restore register bp
                ret                             ;Return to caller
__flog10        endp                            ;End of procedure
_TEXT           ends                            ;End of segment
                end                             ;End of module
