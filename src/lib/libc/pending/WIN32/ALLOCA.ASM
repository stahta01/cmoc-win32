;-----------------------------------------------------------------------------
; __alloca_probe - allocate local stack storage and probe for overflow
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
_DATA           ends

_TEXT           segment                         ;Start of main code segment
__alloca_probe  proc   near                     ;Allocate from stack with probe
                public __alloca_probe           ;Make public for all
                push   ebp                      ;Save register ebp
                mov    ebp,esp                  ;Put current esp in ebp
                add    ebp,8                    ;Point to start of stack frame
                cmp    eax,4096                 ;At least 4k requested ?
                jb     aprobe_2                 ;No, re-direct
aprobe_1:       sub    ebp,4096                 ;Set address for probe
                test   [ebp],ebp                ;Fail if probe in guard page
                sub    eax,4096                 ;Subtract 4k from request
                cmp    eax,4096                 ;At least 4k left ?
                jae    aprobe_1                 ;Yes, check next not guard page
aprobe_2:       sub    ebp,eax                  ;Set final page probe address
                test   [ebp],ebp                ;Fail if probe in guard page
                mov    eax,esp                  ;Save current esp in eax
                mov    esp,ebp                  ;Set esp to allocated area
                mov    ebp,[eax+4]              ;Get return address in eax
                push   ebp                      ;Push return address
                mov    ebp,[eax]                ;Restore register ebp
                ret                             ;Return to caller
__alloca_probe  endp                            ;End of procedure
_TEXT           ends
                end
