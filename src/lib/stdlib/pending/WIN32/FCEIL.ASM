;-----------------------------------------------------------------------------
; __fceil() - floating point ceiling
;-----------------------------------------------------------------------------
                .386
_TEXT           segment use32 para public 'CODE';Start of main code segment
                public  __fceil                 ;Make public for all
__fceil         proc    near                    ;Floating point ceiling
                assume  cs:_TEXT                ;Set default code segment
                push    ebp                     ;Save register bp
                mov     ebp,esp                 ;Point to the stack frame
                sub     esp,4                   ;Allocate temporary space
                fld     qword ptr [ebp+8]       ;Load real from stack
                fstcw   [ebp-2]                 ;Save control word
                fclex                           ;Clear exceptions
                mov     word ptr [ebp-4],0b63h  ;Rounding control word
                fldcw   [ebp-4]                 ;Set new rounding control
                frndint                         ;Round to integer
                fclex                           ;Clear exceptions
                fldcw   [ebp-2]                 ;Restore control word
                mov     esp,ebp                 ;Deallocate temporary space
                pop     ebp                     ;Restore register bp
                ret                             ;Return to caller
__fceil         endp                            ;End of procedure
_TEXT           ends                            ;End of segment
                end                             ;End of module
