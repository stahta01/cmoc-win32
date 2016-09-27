;-----------------------------------------------------------------------------
; __fatan() - floating point arc tangent
;-----------------------------------------------------------------------------
                .386
_TEXT           segment use32 para public 'CODE';Start of main code segment
                public  __fatan                 ;Make public for all
__fatan         proc    near                    ;Floating point arc tangent
                assume  cs:_TEXT                ;Set default code segment
                push    ebp                     ;Save register bp
                mov     ebp,esp                 ;Point to the stack frame
                fld     qword ptr [ebp+8]       ;Load real from stack
                fld1                            ;Load constant 1
                fpatan                          ;Take the arctangent
                pop     ebp                     ;Restore register bp
                ret                             ;Return to caller
__fatan         endp                            ;End of procedure
_TEXT           ends                            ;End of segment
                end                             ;End of module
