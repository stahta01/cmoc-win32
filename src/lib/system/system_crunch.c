
#include "_system.h"

asm char* system_crunch(char* cmd)
{
    asm {
        ldx     2,s
        leax    -1,x                            // charad must be set to the prev char
        stx     _CHARAD
        ldx     #0                              // was -1
        stx     _CURLIN
        pshs    u
        jsr     _GETNCH
        jsr     [handle_crunch]
        puls    u
        ldd     #_LINBUF
    }
}

