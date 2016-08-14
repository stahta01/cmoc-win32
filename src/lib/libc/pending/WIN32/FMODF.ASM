;-----------------------------------------------------------------------------
; __fmodf() - get floating point fractional and integer parts
;-----------------------------------------------------------------------------
                .386
_TEXT           segment use32 para public 'CODE';Start of main code segment
                public  __fmodf                 ;Make public for all
__fmodf         proc    near                    ;Floating point modf
                assume  cs:_TEXT                ;Set default code segment
                push    ebp                     ;Save register bp
                mov     ebp,esp                 ;Point to the stack frame
                push    edi                     ;Save register edi
                fld     qword ptr [ebp+8]       ;Load real from stack
                mov     edi,dword ptr [ebp+16]  ;Put integer address in edi
                fld     st                      ;Duplicate st
                frndint                         ;Round to integer
                fcom    st(1)                   ;Compare with orignal value
                fstsw   ax                      ;Get the FPU status word
                test    byte ptr [ebp+15],080h  ;Test if number is negative
                jz      __fmodf1                ;Re-direct if positive
                sahf                            ;Store AH to flags
                jnb     __fmodf2                ;Re-direct if greater or equal
                fld1                            ;Load the constant 1
                fadd                            ;Increment integer part
                jmp     __fmodf2                ;End of case
__fmodf1:       sahf                            ;Store AH to flags
                jna     __fmodf2                ;Re-direct if less or equal
                fld1                            ;Load constant 1
                fsub                            ;Decrement integer part
__fmodf2:       fst     qword ptr [edi]         ;Store integer part
                fsub                            ;Subtract to get fraction
                pop     edi                     ;Restore register edi
                mov     esp,ebp                 ;Restore stack pointer
                pop     ebp                     ;Restore register bp
                ret                             ;Return to caller
__fmodf         endp                            ;End of procedure
_TEXT           ends                            ;End of segment
                end                             ;End of module
