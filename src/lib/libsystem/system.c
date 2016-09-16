
#include "_system.h"

int _system(void)
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
    }
    return 0;
}

int system(char* cmd)
{
    strcpy(SYSTEM_CMDLINE, cmd);
    return _system();
}

int systemf(char* fmt, ...)
{
    vsprintf(SYSTEM_CMDLINE, fmt, (va_list)&fmt);
    return _system();
}

