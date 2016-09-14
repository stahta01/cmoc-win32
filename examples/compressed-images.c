
// NOTE Due to the bin size, this only works on a no dos extended coco

#pragma org 7680
#pragma options -machine=cocous -nodos

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <conio.h>
#include <equates.h>

#include <crypt.h>

#include "images/1.c"
#include "images/2.c"
#include "images/3.c"
#include "images/4.c"
#include "images/6.c"
#include "images/8.c"

typedef struct {
    unsigned char type;
    unsigned width, height;
    crypt_t crypt;
} cocopic_t;

void ShowImage(cocopic_t* image)
{
    systemf("PMODE%d,1", image->type & 2 ? 3 : 4);
    systemf("SCREEN1,%d", image->type & 1 ? 1 : 0);
    crypt_decode(&image->crypt, (void*)_beggrp, 0);
    sleep(4);
}

int main(void)
{
    for (;;) {
        ShowImage((cocopic_t*)image1);
        ShowImage((cocopic_t*)image2);
        ShowImage((cocopic_t*)image3);
        ShowImage((cocopic_t*)image4);
        ShowImage((cocopic_t*)image6);
        ShowImage((cocopic_t*)image8);
    }
    return 0;
}

