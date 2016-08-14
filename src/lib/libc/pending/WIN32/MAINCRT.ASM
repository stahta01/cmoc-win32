;--------------------------------------------------------------------------
;
; This is the WIN32 C runtime library startup routine _mainCRTStartup
;
; All C programs start here.
;
; Author: A. Maromaty                   Date: 05/24/96
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

_TEXT           segment                         ;Start of main code segment
                extrn   __cstart:near           ;Init & startup
_mainCRTStartup proc    near                    ;Start of all C programs
                public  _mainCRTStartup         ;Make public for all
                cld                             ;Set forward direction
                call    __cstart                ;Init & startup
_mainCRTStartup endp
_TEXT           ends
                end
