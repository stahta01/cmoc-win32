
#include "_system.h"

asm int _system(void)
{
    asm {
        pshs    u
        ldx     #0                              // Was -1
        stx     _CURLIN
        ldx     #_LINBUF
        stx     _CHARAD
        jsr     _GETNCH
        jsr     [sysptr_crunch]
        jsr     _GETNCH
        jsr     [sysptr_execute]
        puls    u
        clrd
    }
}

int system(char* cmd)
{
    strcpy(SYSTEM_CMDLINE, cmd);
    return _system();
}

int systemf(char* fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    vsprintf(SYSTEM_CMDLINE, fmt, args);
    va_end();
    return _system();
}

