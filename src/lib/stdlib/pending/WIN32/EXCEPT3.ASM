;-----------------------------------------------------------------------------
; __except_handler3 - exception handler routine for try blocks
;-----------------------------------------------------------------------------
                  .386

_TEXT             segment para public  USE32 'CODE'
_TEXT             ends
_DATA             segment DWORD public USE32 'DATA'
_DATA             ends
CONST             segment DWORD public USE32 'CONST'
CONST             ends
_BSS              segment DWORD public USE32 'BSS'
_BSS              ends
_TLS              segment DWORD public USE32 'TLS'
_TLS              ends

                  assume  CS:FLAT, DS:FLAT, SS:FLAT

_DATA             segment
_DATA             ends

_TEXT             segment                      ;Start of main code segment
__except_handler3 proc   near                  ;Exception handler routine
                  public __except_handler3     ;Make public for all
                  ret                          ;Return to caller
__except_handler3 endp                         ;End of procedure
_TEXT             ends
                  end
