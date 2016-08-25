
#pragma target coco

#include <stdio.h>
#include <string.h>
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

int system(char* cmd)
{
    strcpy(_linbuf + 1, cmd);
    //_linbuf[0] = 0;
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

int main(void)
{
    system("PMODE 4,1");
    system("SCREEN 1,1");
    system("PCLS 0");
    system("LINE(0,0)-(100,100),PSET");
    system("CIRCLE(128,96),50");
    while (!kbhit()) {
    }
    puts("END OF PROGRAM");
    return 0;
}

