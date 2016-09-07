
#include "_system.h"

char asm polcat(void)
{
    asm {
        jsr     [$a000]
        tfr     a,b
    }
}

void chrout(char c)
{
    asm {
        lda     c
        jsr     [$a002]
    }
}

void asm joyin(void)
{
    asm {
        pshs    u
        jsr     [$A00A]
        puls    u
    }
}

void putchr(char c, char devnum)
{
    char dn = _devnum;
    _devnum = devnum;
    asm {
        lda     c
        jsr     _PUTCHR
    }
    _devnum = dn;
}

char getchr(char devnum)
{
    char c, dn = _devnum;
    _devnum = devnum;
    asm {
        jsr _LA176
        sta c
    }
    _devnum = dn;
    return c;
}

void beep(unsigned char tone, unsigned duration)
{
    asm {
        pshs    u
        lda     tone
        sta     _SNDTON
        ldd     duration
        std     _SNDDUR
        JSR_SOUND
        puls    u
    }
}

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

