
#pragma options -machine=cocous

#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <charset.h>
#include <graph.h>

#include <equates.h>

#include "images/image256x192.c"

int main(void)
{
    int i;
    char s[4];
    bgcolor(3);
    textmode2(MODE_H1_32X24, charset_c64);
    cputs("Are you 18 years or older? ");
    s[0] = sizeof(s) - 2;
    cgets(s);
    if (s[2] == 'y' || s[2] == 'Y') {
        memcpy((void*)_beggrp, image256x192, sizeof(image256x192));
        for (i = 0; i < 4; i++) {
            _memcom((void*)_beggrp, _endgrp - _beggrp);
        }
        cputsxy(0, 22, "Yes, the CoCo just got sexy!\nWelcome to 2016 :-) ");
    } else {
        cputs("\nO, well, you miss out.\n");
    }
    while (!kbhit()) {
    }
    bgcolor(0);
    for (i = 0; i < 24; i++) {
        scrup();
    }
    textmode(0);
    cputs("BACK TO BASIC\n");

    return 0;
}

