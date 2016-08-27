
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
    system("PMODE0,1");
    system("SCREEN1,1");
    system("PCLS1");

    _curpos = _beggrp;
    bgcolor(1);

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

