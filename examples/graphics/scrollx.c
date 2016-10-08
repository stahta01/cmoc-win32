
#pragma options -machine=dragon

#include <equates.h>
#include <stdlib.h>
#include <conio.h>
#include <memory.h>

#include <crypt/image.h>

#include "images/game128x96.c"

int main(void)
{
    system("PMODE1,1");
    cputs("PLEASE WAIT ...");
    crypt_decode(&((crypt_image_t*)image1)->crypt, (void*)_beggrp, 0);
    system("SCREEN1,1");
    while (true) {
        byte* line = (byte*)_beggrp + (9 << 5);
        for (int y = 0; y < 17; y++, line += 32) {
            memrol(line, 32, line[0]);
        }
        line = (byte*)_beggrp + (43 << 5);
        for (int y = 0; y < 15; y++, line += 32) {
            memror(line, 32, line[31]);
        }
    }
    return 0;
}

