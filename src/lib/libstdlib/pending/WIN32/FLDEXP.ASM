;-----------------------------------------------------------------------------
; __fldexp() - floating point x * 2 to the n
;-----------------------------------------------------------------------------
                .386
_TEXT           segment use32 para public 'CODE';Start of main code segment
                public  __fldexp                ;Make public for all
__fldexp        proc    near                    ;Floating point x * 2 to the n
                assume  cs:_TEXT                ;Set default code segment
                push    ebp                     ;Save register bp
                mov     ebp,esp                 ;Point to the stack frame
                sub     esp,8                   ;Allocate temporary space
                fild    dword ptr [ebp+16]      ;Load n as integer
                fld     qword ptr [ebp+8]       ;Load real from stack
                fscale                          ;Compute 2 to the n
                fstp    st(1)                   ;Set new top of stack
                fst     qword ptr [ebp-8]       ;Store result
                mov     esp,ebp                 ;Deallocate temporary space
                pop     ebp                     ;Restore register bp
                ret                             ;Return to caller
                ret                             ;Return to caller
__fldexp        endp                            ;End of procedure
_TEXT           ends                            ;End of segment
                end                             ;End of module
