;-----------------------------------------------------------------------------
; __fsqrt() - floating point square root
;-----------------------------------------------------------------------------
                .386
_TEXT           segment use32 para public 'CODE';Start of main code segment
                public  __fsqrt                 ;Make public for all
__fsqrt         proc    near                    ;Floating point square root
                assume  cs:_TEXT                ;Set default code segment
                push    ebp                     ;Save register bp
                mov     ebp,esp                 ;Point to the stack frame
                fld     qword ptr [ebp+8]       ;Load real from stack
                fsqrt                           ;Take the square root
                pop     ebp                     ;Restore register bp
                ret                             ;Return to caller
__fsqrt         endp                            ;End of procedure
_TEXT           ends                            ;End of segment
                end                             ;End of module
