;-----------------------------------------------------------------------------
; __fpreset() - floating point unit reset
;-----------------------------------------------------------------------------
                .386
_TEXT           segment use32 para public 'CODE';Start of main code segment
                public  __fpreset               ;Make public for all
__fpreset       proc    near                    ;Floating point reset
                assume  cs:_TEXT                ;Set default code segment
                finit                           ;Initialize the FPU
                ret                             ;Return to caller
__fpreset       endp                            ;End of procedure
_TEXT           ends                            ;End of segment
                end                             ;End of module
