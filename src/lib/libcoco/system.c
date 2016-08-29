
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
    //_linbuf[0] = 0;
    return _system();
}

int setstr(char* name, char* value)
{
    stpcpy(stpcpy(stpcpy(stpcpy(_linbuf + 1, name), "$=\""), value), "\"");
    return _system();
}

char* getstr(char* name)
{
    stpcpy(stpcpy(stpcpy(_linbuf + 1, "Z=VARPTR("), name), "$)");
    _system();
    memcpy(_linbuf, (void*)((unsigned*)_varptr)[1], ((unsigned char*)_varptr)[0]);
    _linbuf[((unsigned char*)_varptr)[0]] = 0;
    return _linbuf;
}

int setuint(char* name, unsigned value)
{
    itoa(value, stpcpy(stpcpy(_linbuf + 1, name), "="), 10);
    return _system();
}

unsigned getuint(char* name)
{
    stpcpy(stpcpy(_linbuf + 1, "DEFUSR9="), name);
    _system();
    return ((unsigned*)_usradr)[9];
}

