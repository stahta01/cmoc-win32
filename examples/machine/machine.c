
#pragma options -machine=coco -nodos -noextbas -ram=32

// Relocation required for 16K CoCo. Must removed for DOS systems.
//#pragma org 7680
//#pragma options -machine=cocous -nodos -noextbas -ram=16

//#pragma options -machine=dragon32
//#pragma options -machine=dragon64

#include <stdio.h>
#include <system.h>
#include <machine.h>

char* types[] = {"UNKNOWN", "COCO1", "COCO2", "COCO3", "DRAGON32", "DRAGON64", "RESERVED", "VECTREX"};
char* roms[] = {"UNKNOWN", "STANDARD", "EXTENDED", "SUPER"};

int main(void)
{
    printf("%s %dK %s [%s]\n", types[machine.typ], machine.ram, roms[machine.rom],
           machine.dos ? "DISK" : "NO DISK");
    return 0;
}

