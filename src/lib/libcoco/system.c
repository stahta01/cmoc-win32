
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <equates.h>

#ifdef __COCO__
#define _CRUNCHLINE $B821
#define _PROCESSCOMMAND $ADC6
#endif
#ifdef __DRAGON__
#define _CRUNCHLINE $8F67
#define _PROCESSCOMMAND $84DC
#endif

int _system(void)
{
    //puts(_LINBUF + 1);
    asm {
        pshs u
        ldx     #0  // Was -1
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

int systemf(char* fmt, ...)
{
    vsprintf((char*)_linbuf + 1, fmt, (va_list)&fmt);
    return _system();
}

int system(char* cmd)
{
    strcpy(_linbuf + 1, cmd);
    //_linbuf[0] = 0; // TODO: Unsure what to set this too.
    return _system();
}

