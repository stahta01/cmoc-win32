;-----------------------------------------------------------------------------
; __ftol() - convert floating point to long
;-----------------------------------------------------------------------------
                .386
_TEXT           segment use32 para public 'CODE';Start of main code segment
                public  __ftol                  ;Make public for all
__ftol          proc    near                    ;Convert floating point to long
                assume  cs:_TEXT                ;Set default code segment
                push    ebp                     ;Save register bp
                mov     ebp,esp                 ;Point to the stack frame
                sub     esp,12                  ;Allocate temporary space
                push    ebx                     ;Save register ebx
                push    ecx                     ;Save register ecx
                push    esi                     ;Save register esi
                push    edi                     ;Save register edi
                fstcw   [ebp-2]                 ;Store control word
                mov     ax,[ebp-2]              ;Put control word in ax
                or      ah,0ch                  ;Update flags
                mov     [ebp-4],ax              ;Put control word in ax
                fldcw   [ebp-4]                 ;Load control word
                fistp   dword ptr [ebp-12]      ;Store integer and pop
                fldcw   [ebp-2]                 ;Load control word
                mov     eax,[ebp-12]            ;Get result in eax
                pop     edi                     ;Restore register edi
                pop     esi                     ;Restore register esi
                pop     ecx                     ;Restore register ecx
                pop     ebx                     ;Restore register ebx
                mov     esp,ebp                 ;Free temporary stack space
                pop     ebp                     ;Restore register bp
                ret                             ;Return to caller
__ftol          endp                            ;End of procedure
_TEXT           ends                            ;End of segment
                end                             ;End of module
