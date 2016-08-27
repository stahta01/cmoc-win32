
#include "_conio.h"
#include <stdlib.h>
#include <charset.h>

void textmode(int newmode)
{
    switch (newmode) {
    case MODE_T0_32X16:
    case MODE_T1_32X16:
        system(newmode & 1 ? "SCREEN0,1" : "SCREEN0,0");
        break;
    case MODE_L0_16X12:
    case MODE_L1_16X12:
        system(newmode & 1 ? "SCREEN1,1" : "SCREEN1,0");
        system("PMODE0,1");
        _curpos = _beggrp;
        _conio.fontpack = 0;
        _conio.fontdata = &charset_c64;
        break;
    case MODE_L0_32X12:
    case MODE_L1_32X12:
        system(newmode & 1 ? "SCREEN1,1" : "SCREEN1,0");
        system("PMODE0,1");
        _curpos = _beggrp;
        _conio.fontpack = 1;
        _conio.fontdata = &charset_atari_small;
        break;
    case MODE_M0_16X24:
    case MODE_M1_16X24:
        system("PMODE2,1");
        system(newmode & 1 ? "SCREEN1,1" : "SCREEN1,0");
        _curpos = _beggrp;
        _conio.fontpack = 0;
        _conio.fontdata = &charset_c64;
        break;
    case MODE_M0_32X24:
    case MODE_M1_32X24:
        system("PMODE2,1");
        system(newmode & 1 ? "SCREEN1,1" : "SCREEN1,0");
        _curpos = _beggrp;
        _conio.fontpack = 1;
        _conio.fontdata = &charset_atari_small;
        break;
    case MODE_H0_32X24:
    case MODE_H1_32X24:
        system("PMODE4,1");
        system(newmode & 1 ? "SCREEN1,1" : "SCREEN1,0");
        _curpos = _beggrp;
        _conio.fontpack = 0;
        _conio.fontdata = &charset_c64;
        break;
    case MODE_H0_64X24:
    case MODE_H1_64X24:
        system("PMODE4,1");
        system(newmode & 1 ? "SCREEN1,1" : "SCREEN1,0");
        _curpos = _beggrp;
        _conio.fontpack = 1;
        _conio.fontdata = &charset_atari_small;
        break;
    }
    clrscr();
}

