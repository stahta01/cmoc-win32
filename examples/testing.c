
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

    PCLIP(0, 0, 300, 302);

    PCLS(1);

    PLINE(0, 0, 250, 180, 0);

    for (int i = 0; i < 190; i += 4) {
    PLINE(0, i, i, 190, 0);
    }

    PELLIPSE(60, 60, 20, 20, 0);

    while (!kbhit()) {}
    return 0;
}









































