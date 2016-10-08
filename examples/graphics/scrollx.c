
#pragma options -machine=cocous

#include <equates.h>
#include <stdlib.h>
#include <memory.h>

#include "images/image256x192.c"

int main(void)
{
    system("PMODE4,1:SCREEN1,0");
    memcpy((void*)_beggrp, image256x192, _endgrp - _beggrp);
    while (true) {
        byte* line = (byte*)_beggrp;
        for (int y = 0; y < 192; y++) {
            if (y & 32) {
                memrol(line, 32, line[0] & 128);
            } else {
                memror(line, 32, line[31] & 1);
            }
            line += 32;
        }
    }
    return 0;
}

