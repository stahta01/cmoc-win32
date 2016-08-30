
#pragma options -machine=coco3 -nodos -ram=64

#include <stdio.h>
#include <cmoc.h>

char* machines[] = {
    "UNKNOWN",
    "COLOUR COMPUTER",
    "DRAGON",
    "VECTREX"
};

int main(void)
{
    unsigned char ostype = get_ostype();
    printf("%s %dK %s\n(%s)\n", machines[ostype & 3], ostype & 0x70,
           ostype & CMOC_FLG_EXT ? "EXTENDED" : "STANDARD",
           ostype & CMOC_FLG_DOS ? "DISK" : "NO DISK");
    return 0;
}

