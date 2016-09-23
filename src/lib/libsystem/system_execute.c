
#include "_system.h"

asm int system_execute(char* cmd)
{
    asm {
        ldx     2,s
        leax    -1,x                            // charad must be set to the pev char
        stx     _CHARAD
        pshs    u
        execute_loop:
        jsr     _GETNCH
        jsr     [sysptr_execute]
        lda     [_CHARAD]
        cmpa    #':'
        beq     execute_loop
        puls    u
        clrd
    }
}

