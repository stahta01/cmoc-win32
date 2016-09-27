;-----------------------------------------------------------------------------
; __ftan() - floating point tangent
;-----------------------------------------------------------------------------
                .386
_TEXT           segment use32 para public 'CODE';Start of main code segment
                public  __ftan                  ;Make public for all
__ftan          proc    near                    ;Floating point tangent
                assume  cs:_TEXT                ;Set default code segment
                push    ebp                     ;Save register bp
                mov     ebp,esp                 ;Point to the stack frame
                sub     esp,4                   ;Allocate temporary space
                fld     qword ptr [ebp+8]       ;Load real from stack
                fptan                           ;Take the tangent
                fstp    dword ptr [ebp-4]       ;Throw away the constant 1
                mov     esp,ebp                 ;Deallocate temporary space
                pop     ebp                     ;Restore register bp
                ret                             ;Return to caller
__ftan          endp                            ;End of procedure
_TEXT           ends                            ;End of segment
                end                             ;End of module
