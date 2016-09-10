
#pragma options -machine=coco -nodos -noextbas -ram=16

#include <stdio.h>
#include <system.h>

char* machines[] = {"UNKNOWN", "COCO1", "COCO2", "COCO3", "DRAGON32", "DRAGON64", "RESERVED", "VECTREX"};

int main(void)
{
    // You can use either the global var _get_ostype or the function get_ostype()
    unsigned char ostype = _get_ostype;
    printf("%s %dK %s [%s]\n", machines[ostype & 7], ostype & 0x70,
           ostype & SYSTEM_FLG_EXT ? "EXTENDED" : "STANDARD",
           ostype & SYSTEM_FLG_DOS ? "DISK" : "NO DISK");
    return 0;
}

