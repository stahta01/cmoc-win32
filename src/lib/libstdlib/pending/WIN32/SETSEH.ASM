;-----------------------------------------------------------------------------
; __SetExceptionHandler() - Set structured exception handler
;-----------------------------------------------------------------------------
                       .386

_TEXT                  segment para public use32 'CODE'
_TEXT                  ends
_DATA                  segment dword public use32 'DATA'
_DATA                  ends
CONST                  segment dword public use32 'CONST'
CONST                  ends
_BSS                   segment dword public use32 'BSS'
_BSS                   ends
_TLS                   segment dword public use32 'TLS'
_TLS                   ends

                       assume  cs:flat, ds:flat, ss:flat, es:flat

_TEXT                  segment para public use32 'CODE'
;
; _SetExceptionHandler() - Set structured exception handler
;
;  ECX - exception registration record pointer
;
                        public  @_SetExceptionHandler@4
@_SetExceptionHandler@4 proc    near            ;Start of procedure
                                                ;Get head of SEH chain ptr
                        mov     eax,dword ptr fs:[0]
                                                ;Set previous SEH pointer
                        mov     dword ptr [ecx],eax
                                                ;Set new SEH pointer
                        mov     dword ptr fs:[0],ecx
                        ret                     ;Return to caller
@_SetExceptionHandler@4 endp                    ;End of procedure
_TEXT                   ends
                        end
