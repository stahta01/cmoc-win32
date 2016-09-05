
// NOTE Due to the bin size, this only works on a no dos extended coco

#pragma org 7680
#pragma options -machine=cocous -nodos

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <conio.h>
#include <equates.h>

#include <lzss.h>
#include <exodecr.h>

#include "images/1.c"
#include "images/2.c"
#include "images/3.c"
#include "images/4.c"
#include "images/6.c"
#include "images/8.c"

typedef struct {
    unsigned char type;
    unsigned dstsize, srcsize;
} data_t;

typedef struct {
    unsigned char type;
    unsigned width, height;
    data_t data;
} cocopic_t;

void ShowImage(cocopic_t* image)
{
    systemf("PMODE%d,1", image->type & 2 ? 3 : 4);
    systemf("SCREEN1,%d", image->type & 1 ? 1 : 0);
    switch (image->data.type) {
    case 0:
        memcpy((void*)_beggrp, image + 1, image->data.srcsize);
        break;
    case 1:
        exo_decrunch((char*)(image + 1) + image->data.srcsize, (char*)_endgrp);
        break;
    case 12:                                // 4096 ring buffer (1 << 12) = 4096
        decompress_lzss((unsigned char*)_beggrp, (unsigned char*)(image + 1), image->data.srcsize);
        break;
    }
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

