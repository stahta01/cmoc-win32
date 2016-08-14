;-----------------------------------------------------------------------------
; __fabs() - floating point absolute value
;-----------------------------------------------------------------------------
                .386
_TEXT           segment use32 para public 'CODE';Start of main code segment
                public  __fabs                  ;Make public for all
__fabs          proc    near                    ;Floating point abs value
                assume  cs:_TEXT                ;Set default code segment
                push    ebp                     ;Save register bp
                mov     ebp,esp                 ;Point to the stack frame
                fld     qword ptr [ebp+8]       ;Load real from stack
                fabs                            ;Take the absolute value
                pop     ebp                     ;Restore register bp
                ret                             ;Return to caller
__fabs          endp                            ;End of procedure
_TEXT           ends                            ;End of segment
                end                             ;End of module
