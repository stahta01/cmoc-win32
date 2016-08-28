
#pragma target coco

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <basic.h>

#include <charset.h>
#include <equates.h>

void _textmode(int newmode)
{
    system(newmode & 1 ? "SCREEN0,1" : "SCREEN0,0");
    beep(1,1);

    switch (newmode) {
    case MODE_L0_16X12:
    case MODE_L1_16X12:
        system("SCREEN1");
        system("PMODE0");
        _curpos = _beggrp;
        _conio.fontpack = 0;
        _conio.fontdata = &charset_c64;
        break;
    case MODE_L0_32X12:
    case MODE_L1_32X12:
        system("PMODE0");
        system("SCREEN1");
        _curpos = _beggrp;
        _conio.fontpack = 1;
        _conio.fontdata = &charset_atari_small;
        break;
    case MODE_M0_16X24:
    case MODE_M1_16X24:
        system("SCREEN1");
        system("PMODE2");
        _curpos = _beggrp;
        _conio.fontpack = 0;
        _conio.fontdata = &charset_c64;
        break;
    case MODE_M0_32X24:
    case MODE_M1_32X24:
        system("PMODE2");
        system("SCREEN1");
        _curpos = _beggrp;
        _conio.fontpack = 1;
        _conio.fontdata = &charset_atari_small;
        break;
    case MODE_H0_32X24:
    case MODE_H1_32X24:
        system("PMODE4");
        system("SCREEN1");
        _curpos = _beggrp;
        _conio.fontpack = 0;
        _conio.fontdata = &charset_c64;
        break;
    case MODE_H0_64X24:
    case MODE_H1_64X24:
        system("PMODE4");
        system("SCREEN1");
        _curpos = _beggrp;
        _conio.fontpack = 1;
        _conio.fontdata = &charset_atari_small;
        break;
    }
    clrscr();
}

void cputs_center(char* s)
{
    unsigned char w, h;
    screensize(&w, &h);
    gotox((unsigned char)((w - strlen(s)) >> 1));
    cputs(s);
    cputc('\n');
}

int main(void)
{
    int mode = MODE_T0_32X16;
    char s[10];

    CLIP(0, 0, 256, 192);

    for (;;) {
        bgcolor(1);
        _textmode(mode);

        cputs_center("Welcome to conio.h");
        cputs_center("for CMOC");
        cputs_center("----------------------");
        cputs("\n");
        cputs_center("1) 32x16");
        cputs_center("2) 16x12");
        cputs_center("3) 32x12");
        cputs_center("4) 16x24");
        cputs_center("5) 32x24 (packed)");
        cputs_center("6) 32x24");
        cputs_center("7) 64x24");
        cputs_center("X) Exit to BASIC");
        cputs("\nEnter mode number: ");
        s[0] = 1;
        cgets(s);
        switch (s[2]) {
        case '1':
            mode = MODE_T0_32X16;
            break;
        case '2':
            mode = MODE_L0_16X12;
            break;
        case '3':
            mode = MODE_L0_32X12;
            break;
        case '4':
            mode = MODE_M0_16X24;
            break;
        case '5':
            mode = MODE_M0_32X24;
            break;
        case '6':
            mode = MODE_H0_32X24;
            break;
        case '7':
            mode = MODE_H0_64X24;
            break;
        case 'X':
            textmode(MODE_T0_32X16);
            cputs("RETURN TO BASIC\n");
            exit(0);
        }
    }
    return 0;
}

