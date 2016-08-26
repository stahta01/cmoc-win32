
#pragma target coco

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

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
        ldx     #$FFFF
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

int setint(char* name, int value)
{
    itoa(value, stpcpy(stpcpy(_linbuf + 1, name), "="), 10);
    return _system();
}

int getint(char* name)
{
    stpcpy(stpcpy(_linbuf + 1, "DEFUSR9="), name);
    _system();
    return ((int*)_USR0)[9];
}

int main(void)
{
    system("PMODE 4,1");
    system("PCLS 0");
    system("SCREEN 1,1");
    system("LINE(0,0)-(100,100),PSET");
    system("CIRCLE(128,96),50");

    _fretop = 0x2600;
    _strtab = _frespc = _memsiz = 0x2700;
    char s[100];

    setstr("A", "DEREK");
    setstr("B", "EVANS");
    puts(getstr("A"));
    puts(getstr("B"));

    setint("A", 123);
    printf("A=%d\n", getint("A"));
    while (!kbhit()) {
    }
    puts("END OF PROGRAM");
    return 0;
}

