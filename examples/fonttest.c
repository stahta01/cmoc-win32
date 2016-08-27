
#pragma target dragon

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <equates.h>
#include <charset.h>
#include <conio.h>
#include <ctype.h>

#define C32  1
#define BW16 2
#define BG32 3
#define BW32 4
#define BW64 5
#define BG64 6

void textmode(int newmode)
{
    if (newmode == C32) {
        system("SCREEN0,0");
        system("CLS");
    }
    switch (newmode) {
    case C32:
        system("SCREEN0,0");
        system("CLS");
        break;
    case BG32:
    case BW32:
        system("PMODE2,1");
        system("PCLS0");
        system(newmode == BG32 ? "SCREEN1,0" : "SCREEN1,1");
        bgcolor(0);
        _curpos = _beggrp;
        _conio.fontpack = 1;
        _conio.fontdata = &charset_atari_small;
        break;
    case BW64:
    case BG64:
        system("PMODE4,1");
        system("PCLS0");
        system(newmode == BG64 ? "SCREEN1,0" : "SCREEN1,1");
        bgcolor(0);
        _curpos = _beggrp;
        _conio.fontpack = 1;
        _conio.fontdata = &charset_atari_small;
        break;
    }
}

int main(void)
{
    textmode(BW32);
    char s[100];
    int i;
    for (;;) {
        for (i = 0; i < 20; i++) {
            gotox((unsigned char)i);
            sprintf(s, "HELLO THERE %d\n", wherex());
            cputs(s);
        }
        s[0] = 63;
        cgets(s);
        cputc('\n');
        printf("YOU ENTERED %s\n", s + 2);
    }
    return 0;
}

