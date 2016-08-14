;-----------------------------------------------------------------------------
; __fmod() - floating point remainder of x/y
;-----------------------------------------------------------------------------
                .386
_TEXT           segment use32 para public 'CODE';Start of main code segment
                public  __fmod                  ;Make public for all
__fmod          proc    near                    ;Floating point remainder
                assume  cs:_TEXT                ;Set default code segment
                push    ebp                     ;Save register bp
                mov     ebp,esp                 ;Point to the stack frame
                fld     qword ptr [ebp+16]      ;Load real from stack
                fld     qword ptr [ebp+8]       ;Load real from stack
__fmod1:        fprem                           ;Get the partial remainder
                fstsw   ax                      ;Get coprocessor status
                test    ax,0400h                ;Complete remainder ?
                jnz     __fmod1                 ;No, go get next remainder
                fstp    st(1)                   ;Set new top of stack
                pop     ebp                     ;Restore register bp
                ret                             ;Return to caller
__fmod          endp                            ;End of procedure
_TEXT           ends                            ;End of segment
                end                             ;End of module
