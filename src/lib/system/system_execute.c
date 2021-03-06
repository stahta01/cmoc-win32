
#include "_system.h"

asm void system_execute(char* cmd)
{
    asm {
        ldx     2,s
        leax    -1,x                            // charad must be set to the prev char
        stx     _CHARAD
        pshs    u
        execute_loop:
        jsr     _GETNCH
        jsr     [handle_execute]
        lda     [_CHARAD]
        cmpa    #':'
        beq     execute_loop
        puls    u
    }
}

