;-----------------------------------------------------------------------------
; setjmp()/longjmp() - set/perform non-local jump
;-----------------------------------------------------------------------------
         .386

_TEXT    segment para public use32 'CODE'
_TEXT    ends
_DATA    segment dword public use32 'DATA'
_DATA    ends
CONST    segment dword public use32 'CONST'
CONST    ends
_BSS     segment dword public use32 'BSS'
_BSS     ends
_TLS     segment dword public use32 'TLS'
_TLS     ends

         assume  cs:flat, ds:flat, ss:flat, es:flat

_TEXT    segment para public use32 'CODE'
         extrn   _RtlUnwind@16 : NEAR
;
; _setjmp() - This routine accepts the following parameters:
;
;        [ESP+4]         jump buffer pointer
;
         public  _setjmp                        ;Make public for all
_setjmp  proc    near                           ;Start of setjmp procedure
         mov     edx,dword ptr [esp+4]          ;Get jump buffer pointer
         mov     ecx,dword ptr [esp]            ;Load the return address
         mov     eax,dword ptr fs:[0]           ;Head of exception chain pointer
         mov     dword ptr [edx+12],ebx         ;Store register ebx
         mov     dword ptr [edx+16],esi         ;Store register esi
         mov     dword ptr [edx+20],edi         ;Store register edi
         mov     dword ptr [edx+8],ecx          ;Store the return address
         mov     dword ptr [edx+28],eax         ;Store head of exception chain
         mov     dword ptr [edx+4],ebp          ;Store frame pointer
         mov     eax,esp                        ;Get current esp
         add     eax,4                          ;Discard return address
         mov     dword ptr [edx],eax            ;Store callers esp
         xor     eax,eax                        ;Set the return code to zero
         ret                                    ;Return to caller
_setjmp  endp
;
; _longjmp() - This routine accepts the following parameters:
;
;        [ESP+4]         jump buffer pointer
;        [ESP+8]         return value
;
         public  _longjmp                       ;Make public for all
_longjmp proc    near                           ;Start of longjmp procedure
         mov     ebp,esp                        ;Point to the stack frame
         mov     edx,dword ptr [ebp+4]          ;Get jump buffer pointer
         mov     eax,dword ptr [edx+28]         ;Get head of exception chn ptr
         cmp     eax,dword ptr fs:[0]           ;At head of exception chain ?
         je      ljp1                           ;Yes, no need to unwind
         push    0                              ;Push zero
         push    0                              ;Push zero
         push    offset flat:ljp1               ;Push offset return address
         push    dword ptr [edx+28]             ;Push head of exception chn ptr
         call    _RtlUnwind@16                  ;Unwind any exceptions
ljp1:    mov     edx,dword ptr [ebp+4]          ;Get jump buffer pointer
         mov     eax,dword ptr [ebp+8]          ;Get return value
         or      eax,eax                        ;Return value zero ?
         jnz     ljp2                           ;No, proceed
         mov     eax,1                          ;Set return value to 1
ljp2:    mov     ebx,dword ptr [edx+12]         ;Restore register ebx
         mov     esi,dword ptr [edx+16]         ;Restore register ebx
         mov     edi,dword ptr [edx+20]         ;Restore register ebx
         mov     ecx,dword ptr [edx+8]          ;Get the return address
         mov     ebp,dword ptr [edx+4]          ;Restore stack frame pointer
         mov     esp,dword ptr [edx]            ;Restore caller stack pointer
         jmp     ecx                            ;Jump to the return address
_longjmp endp
_TEXT    ends
         end
