
// Ive added a header file "machine.h" with machine checking macros in it.
// It should work for a standard machine, unless someone is running a modified
// ROM, which probably means, you wont be able to call ROM routines anyway.
// Please email me if these are wrong. They rely on copyright messages in ROM.

#include <machine.h>
#include <conio.h>

int main(void)
{
    clrscr();

    cwritef("YOU ARE RUNNING THE FOLLOWING\n\n");

    cwritef("COLOR BASIC    V%d.%d\n", MAC_COLBAS_MAJOR, MAC_COLBAS_MINOR);
    cwritef("EXTENDED BASIC V%d.%d\n", MAC_EXTBAS_MAJOR, MAC_EXTBAS_MINOR);
    cwritef("DISK BASIC     V%d.%d\n", MAC_DSKEXT_MAJOR, MAC_DSKEXT_MINOR);

    cputs("\n\nBACK TO BASIC\n");

    return 0;
}

