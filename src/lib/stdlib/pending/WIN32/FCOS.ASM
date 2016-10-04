;-----------------------------------------------------------------------------
; __fcos() - floating point cosine
;-----------------------------------------------------------------------------
                .386
_TEXT           segment use32 para public 'CODE';Start of main code segment
                public  __fcos                  ;Make public for all
__fcos          proc    near                    ;Floating point cosine
                assume  cs:_TEXT                ;Set default code segment
                push    ebp                     ;Save register bp
                mov     ebp,esp                 ;Point to the stack frame
                fld     qword ptr [ebp+8]       ;Load real from stack
                fcos                            ;Take the cosine
                pop     ebp                     ;Restore register bp
                ret                             ;Return to caller
__fcos          endp                            ;End of procedure
_TEXT           ends                            ;End of segment
                end                             ;End of module
