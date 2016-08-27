
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <equates.h>
#include <charset.h>
#include <conio.h>
#include <ctype.h>

int main(void)
{
    system("PMODE4,1");
    system("SCREEN1,0");
    system("PCLS0");

    _curpos = _beggrp;

    _conio.fontpack = 1;
    _conio.fontdata = &charset_atari_small;

    char s[100];
    int i;
    for (;;) {
        sprintf(s, "HELLO THERE %d\n", i++);
        cputs(s);
        s[0] = 63;
        cgets(s);
        cputc('\n');
        printf("YOU ENTERED %s\n", s + 2);
    }
    return 0;
}

