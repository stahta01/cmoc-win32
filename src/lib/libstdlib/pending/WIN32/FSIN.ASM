;-----------------------------------------------------------------------------
; __fsin() - floating point sine
;-----------------------------------------------------------------------------
                .386
_TEXT           segment use32 para public 'CODE';Start of main code segment
                public  __fsin                  ;Make public for all
__fsin          proc    near                    ;Floating point sine
                assume  cs:_TEXT                ;Set default code segment
                push    ebp                     ;Save register bp
                mov     ebp,esp                 ;Point to the stack frame
                fld     qword ptr [ebp+8]       ;Load real from stack
                fsin                            ;Take the sine
                pop     ebp                     ;Restore register bp
                ret                             ;Return to caller
__fsin          endp                            ;End of procedure
_TEXT           ends                            ;End of segment
                end                             ;End of module
