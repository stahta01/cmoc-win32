;--------------------------------------------------------------------------
;
; This is the WIN32 C runtime startup routine for the COBOL runtime DLLs
;
;                  __DllMainCrtStartup@12
;
; All C programs start here.
;
; Author: A. Maromaty                   Date: 06/19/96
;
;-----------------------------------------------------------------------------
                .386

_TEXT           segment para public  USE32 'CODE'
_TEXT           ends
_DATA           segment DWORD public USE32 'DATA'
_DATA           ends
CONST           segment DWORD public USE32 'CONST'
CONST           ends
_BSS            segment DWORD public USE32 'BSS'
_BSS            ends
_TLS            segment DWORD public USE32 'TLS'
_TLS            ends

                assume  CS:FLAT, DS:FLAT, SS:FLAT

_DATA           segment
                public  __crt_base              ;C runtime base pointer
                public  __crt_errno             ;C runtime errno pointer
                public  __fltused               ;Floating point used flag
                public  __infinity              ;Floating point infinity
                public  __except_list           ;Exception list base offset
__crt_base      dd      0                       ;C runtime base pointer
__crt_errno     dd      0                       ;C runtime errno pointer
__fltused       dd      0                       ;Floating point used flag
__infinity      db      6 dup(0), 0f0h, 07fh    ;Floating point infinity
__except_list   equ     0                       ;Exception list base offset
_DATA           ends

_TEXT                  segment                  ;Start of main code segment
                       extrn   __dllstart:near  ;Init & startup
                       extrn   _DllMain@12:near ;User's Dll startup code
__DllMainCRTStartup@12 proc    near             ;DLL startup routine
                                                ;Make public for all
                       public  __DllMainCRTStartup@12
                       push    ebp              ;Save register ebp
                       mov     ebp,esp          ;Point to local stack frame
                       cld                      ;Set forward direction
                       call    __dllstart       ;Init & startup
                       push    [ebp+12]         ;Push reserved field
                       push    [ebp+8]          ;Push reason for call
                       push    [ebp+4]          ;Push module handle
                       call    _DllMain@12      ;Call the user's DLL main
                       pop     ebp              ;Restore register ebp
                       ret     12               ;Return to caller
__DllMainCRTStartup@12 endp
_TEXT                  ends
                       end
