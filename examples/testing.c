
// This file is uses for testing of new functions. It may
// not contain useful code.

#pragma org $3600

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#include <basic.h>
#include <motorola.h>

int main(void)
{
    MotorolaSetVDG(_SAM_0C00, _VDG_GRAPH_6R1);

    _beggrp = 0x0C00;
    _endgrp = _beggrp + (24 << 8);
    _horbyt = 32;
    _pmode = 5;

    PCLIP(0, 0, 300, 302);

    PCLS(1);

    PLINE(0, 0, 250, 180, 0);

    for (int i = 2; i < 190; i += 8) {
        PLINE(2, i, i, 190, 2);
    }

    PELLIPSE(128, 96, 70, 40, 3);

    while (!kbhit()) {}

    return 0;
}










































