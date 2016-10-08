
//#pragma options -machine=cocous

#include <equates.h>
#include <stdlib.h>
#include <memory.h>

#include <crypt/image.h>

#include "images/game128x96.c"

int main(void)
{
    system("PMODE1,1:SCREEN1,0");
    crypt_decode(&((crypt_image_t*)image1)->crypt, (void*)_beggrp, 0);
    while (true) {
        byte* line = (byte*)_beggrp + (9 << 5);
        for (int y = 0; y < 17; y++, line += 32) {
            memrol(line, 32, line[0] & 128);
        }
        line = (byte*)_beggrp + (43 << 5);
        for (int y = 0; y < 15; y++, line += 32) {
            memror(line, 32, line[31] & 1);
        }
    }
    return 0;
}

