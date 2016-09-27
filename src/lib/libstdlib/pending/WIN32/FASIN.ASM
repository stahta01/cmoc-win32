;-----------------------------------------------------------------------------
; __fasin() - floating point arc sine
;-----------------------------------------------------------------------------
                .386
_TEXT           segment use32 para public 'CODE';Start of main code segment
                public  __fasin                 ;Make public for all
__fasin         proc    near                    ;Floating point arc sine
                assume  cs:_TEXT                ;Set default code segment
                push    ebp                     ;Save register bp
                mov     ebp,esp                 ;Point to the stack frame
                fld     qword ptr [ebp+8]       ;Load real from stack
                fld     st(0)                   ;Load x
                fld     st(0)                   ;Load x
                fmul                            ;Multiply (x squared)
                fld1                            ;Load 1
                fsubr                           ;1 - (x squared)
                fsqrt                           ;Square root of (1 - x squared)
                fpatan                          ;This gives the arc sine !
                pop     ebp                     ;Restore register bp
                ret                             ;Return to caller
__fasin         endp                            ;End of procedure
_TEXT           ends                            ;End of segment
                end                             ;End of module
