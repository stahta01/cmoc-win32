
#include <basic.h>
#include <conio.h>

int main(void)
{
    bgcolor(1);
    textmode(MODE_M0_16X24);
    CLIP(0, 0, 256, 192);
    cprintf("Saving graphics to disk\n");
    ELLIPSE(128,96, 100, 50, 0);
    SAVEM("TEST", (void*)_beggrp, (void*)_endgrp, 0);
    PCLS(0);
    LOADM("TEST", 0);
    cprintf("\n\nGraphics loaded\n");
    cprintf("Press anykey\n");
    getch();
    textmode(MODE_T0_32X16);
    puts("BACK TO BASIC");
    return 0;
}
