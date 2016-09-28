
// This example requires the coco2b (6847t1 support) or CoCo3
#pragma options -machine=coco2b

#include <conio.h>

int main(void)
{
    *(byte*)65314 |= 16;

    clrscr();

    cputs("The VDG 6847t1 chip supported\n");
    cputs("lowercase text.\n");
    cputs("Only the last of the CoCo 2's\n");
    cputs("and the CoCo 3's have this mode\n\n");
    cputs("Press any key to return to the\n");
    cputs("old CoCo text display.\n\n");

    return 0;
}

