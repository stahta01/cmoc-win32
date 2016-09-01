
#pragma target coco
#pragma options -machine=cocous

#include <stdio.h>
#include <stdlib.h>
#include <basic.h>
#include <conio.h>
#include <equates.h>

int main(void)
{
    int x, y;
    char* p;
    textmode(MODE_H0_32X24);

    *(unsigned char*)0xff22 &= 127;

    //for (p = _beggrp; p <= _endgrp; p++) {
        //*p = 128;
    //}
    //puts("Hello there from Derek");
    // return 0;
    for (x = 0; x < 8; x++) {
        *(unsigned char*)0xff22 = (*(unsigned char*)0xff22 & 0x8f) | (x << 4);
        for (y = 0; y < 8; y++) {
            ((unsigned char*)0xffc0)[(y & 1) != 0] = 0;
            ((unsigned char*)0xffc2)[(y & 2) != 0] = 0;
            ((unsigned char*)0xffc4)[(y & 4) != 0] = 0;
            getch();
        }
    }
    return -1;
}

