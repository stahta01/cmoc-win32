
// This file is uses for testing of new functions. It may
// not contain useful code.

#include <stdio.h>
#include <string.h>
#include <conio.h>

#include <basic.h>
#include <motorola.h>

int main(void)
{
    MotorolaSetVDG(_SAM_FE00, _VDG_GRAPH_6R1);

    //printf("%d\n", strlen(""));

    while (!kbhit()) {}
    return 0;
}





