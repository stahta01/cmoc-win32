
#include "_system.h"

int _system(void)
{
    //puts(_syscmdline);
    asm {
        pshs u
        ldx     #0                          // Was -1
        stx     _CURLIN
        ldx     #_LINBUF
        stx     _CHARAD
        jsr     _GETNCH
        jsr     _CRUNCHLINE
        jsr     _GETNCH
        jsr     _PROCESSCOMMAND
        puls u
    }
    return 0;
}

int system(char* cmd)
{
    strcpy(_syscmdline, cmd);
    return _system();
}

int systemf(char* fmt, ...)
{
    vsprintf(_syscmdline, fmt, (va_list)&fmt);
    return _system();
}

