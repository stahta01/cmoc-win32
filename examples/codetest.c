
#pragma target coco
#pragma options -machine=coco2b

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    //*(unsigned char*)0x95ac = 57;
    *(unsigned char*)0xff22 |= 32 | 16 | 8;

    puts("Start");
    puts("EXIT");
    return -1;
}

