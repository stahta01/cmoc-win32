
#pragma options -machine=cocous

#include <string.h>
#include <conio.h>
#include <equates.h>
#include <charset.h>

#include "image256x192.c"

int main(void)
{
    char s[4];
    bgcolor(1);
    textmode2(MODE_H1_32X24, charset_c64);
    cputs("Are you 18 years or older? ");
    s[0] = sizeof(s) - 2;
    cgets(s);
    if (s[2] == 'y' || s[2] == 'Y') {
        memcpy((void*)_beggrp, image256x192, sizeof(image256x192));
        gotoxy(0, 22);
        cputs("Yes, its porn on the CoCo!\n");
        cputs("Welcome to 2016 :-) ");
    } else {
        cputs("\nO, well, you miss out.\n");
    }
    while (!kbhit()) {
    }
    textmode(0);
    cputs("BACK TO BASIC\n");

    return 0;
}

