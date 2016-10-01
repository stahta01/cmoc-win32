
//#pragma options -machine=coco -nodos -noextbas -ram=32

// Relocation required for 16K CoCo. Must removed for DOS systems.
#pragma org 7680
#pragma options -machine=cocous -nodos -noextbas -ram=16

//#pragma options -machine=dragon32
//#pragma options -machine=dragon64

#include <stdio.h>
#include <system.h>

char* machines[] = {"UNKNOWN", "COCO1", "COCO2", "COCO3", "DRAGON32", "DRAGON64", "RESERVED", "VECTREX"};

int main(void)
{
    // You can use either the global var _get_ostype or the function get_ostype()
    byte ostype = _get_ostype;
    printf("%s %dK %s [%s]\n", machines[ostype & 7], ostype & 0x70,
           ostype & SYSTEM_FLG_EXT ? "EXTENDED" : "STANDARD",
           ostype & SYSTEM_FLG_DOS ? "DISK" : "NO DISK");
    return 0;
}

