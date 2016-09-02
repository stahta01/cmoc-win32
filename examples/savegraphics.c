
#include <basic.h>
#include <conio.h>

int main(void)
{
    bgcolor(1);
    textmode(MODE_M0_16X24);
    MCLIP(0, 0, 256, 192);
    cprintf("Saving graphics to disk\n");
    MELLIPSE(128,96, 100, 50, 0);
    SAVEM("PICTURE.IMG", (void*)_beggrp, (void*)_endgrp - 1, 0);
    PCLS(0);
    LOADM("PICTURE.IMG", 0);
    cprintf("\n\nGraphics loaded\n");
    cprintf("Press anykey\n");
    getch();
    textmode(MODE_T0_32X16);
    puts("BACK TO BASIC");
    return 0;
}
