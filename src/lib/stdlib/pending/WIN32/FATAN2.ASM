;-----------------------------------------------------------------------------
; __fatan2() - floating point arc tangent (2 argument)
;-----------------------------------------------------------------------------
                .386
_TEXT           segment use32 para public 'CODE';Start of main code segment
                public  __fatan2                ;Make public for all
__fatan2        proc    near                    ;Floating point arc tangent2
                assume  cs:_TEXT                ;Set default code segment
                push    ebp                     ;Save register bp
                mov     ebp,esp                 ;Point to the stack frame
                fld     qword ptr [ebp+8]       ;Load real from stack
                fld     qword ptr [ebp+16]      ;Load real from stack
                fpatan                          ;Take the arctangent
                mov     esp,ebp                 ;Restore stack pointer
                pop     ebp                     ;Restore register bp
                ret                             ;Return to caller
__fatan2        endp                            ;End of procedure
_TEXT           ends                            ;End of segment
                end                             ;End of module
