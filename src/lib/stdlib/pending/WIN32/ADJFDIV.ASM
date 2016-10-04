;-----------------------------------------------------------------------------
; Adjust for Pentium floating point fdiv and fdivr bug
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
                public  __adjust_fdiv           ;Make public for all
__adjust_fdiv   dd      0                       ;Adjust for Pentium fdiv flag
_DATA           ends

_TEXT           segment                         ;Start of main code segment
;
; This routine adjusts for the Pentium 32 bit fdiv bug if the __adjust_fdiv
; flag is non-zero. This routine is currently not implemented for
; the replacement C runtime system
;
__adj_fdiv_m32  proc   near                     ;Adjust for 32 bit fdiv bug
                public __adj_fdiv_m32           ;Make public for all
                int    3                        ;Issue breakpoint if called
                ret    4                        ;Return to caller
__adj_fdiv_m32  endp
;
; This routine adjusts for the Pentium 32 bit fdivr bug if the __adjust_fdiv
; flag is non-zero. This routine is currently not implemented for
; the replacement C runtime system
;
__adj_fdivr_m32 proc   near                     ;Adjust for 32 bit fdivr bug
                public __adj_fdivr_m32          ;Make public for all
                int    3                        ;Issue breakpoint if called
                ret    4                        ;Return to caller
__adj_fdivr_m32 endp
;
; This routine adjusts for the Pentium 64 bit fdiv bug if the __adjust_fdiv
; flag is non-zero. This routine is currently not implemented for
; the replacement C runtime system
;
__adj_fdiv_m64  proc   near                     ;Adjust for 64 bit fdiv bug
                public __adj_fdiv_m64           ;Make public for all
                int    3                        ;Issue breakpoint if called
                ret    8                        ;Return to caller
__adj_fdiv_m64  endp
;
; This routine adjusts for the Pentium 64 bit fdivr bug if the __adjust_fdiv
; flag is non-zero. This routine is currently not implemented for
; the replacement C runtime system
;
__adj_fdivr_m64 proc   near                     ;Adjust for 64 bit fdivr bug
                public __adj_fdivr_m64          ;Make public for all
                int    3                        ;Issue breakpoint if called
                ret    8                        ;Return to caller
__adj_fdivr_m64 endp
_TEXT           ends
                end
