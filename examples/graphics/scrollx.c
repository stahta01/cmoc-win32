
#pragma options -machine=dragon

#include <equates.h>
#include <stdlib.h>
#include <conio.h>
#include <memory.h>

#include <crypt/image.h>

#include "images/game128x96.c"

asm void memrol2(void* dst, void* src, size_t size)
{
}

int main(void)
{
    system("PMODE1,1");
    cputs("PLEASE WAIT ...");
    crypt_decode(&((crypt_image_t*)image1)->crypt, (void*)_beggrp, 0);
    system("SCREEN1,1");
    while (true) {
        byte* line = (byte*)_beggrp + (9 << 5);
        for (int y = 0; y < 17; y++, line += 32) {
            memrol(line, line[0], 32);
        }
        line = (byte*)_beggrp + (43 << 5);
        for (int y = 0; y < 15; y++, line += 32) {
            memror(line, line[31], 32);
        }
    }
    return 0;
}

