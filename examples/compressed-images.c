
// NOTE Due to the bin size, this only works on a no dos extended coco

#pragma org 7680
#pragma options -machine=cocous -nodos

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <conio.h>
#include <equates.h>

#include <crypt/image.h>

#include "images/1.c"
#include "images/2.c"
#include "images/3.c"
#include "images/4.c"
#include "images/6.c"
#include "images/8.c"

void ShowImage(crypt_image_t* image)
{
    systemf("PMODE%d,1", image->type & CRYPT_IMAGE_TYPE_COL ? 3 : 4);
    systemf("SCREEN1,%d", image->type & CRYPT_IMAGE_TYPE_CSS ? 1 : 0);
    crypt_decode(&image->crypt, (void*)_beggrp, 0);
    sleep(4);
}

int main(void)
{
    for (;;) {
        ShowImage((crypt_image_t*)image1);
        ShowImage((crypt_image_t*)image2);
        ShowImage((crypt_image_t*)image3);
        ShowImage((crypt_image_t*)image4);
        ShowImage((crypt_image_t*)image6);
        ShowImage((crypt_image_t*)image8);
    }
    return 0;
}

