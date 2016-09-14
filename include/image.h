
#ifndef _IMAGE_H
#define _IMAGE_H

#include <crypt.h>

#define IMAGE_TYPE_CSS      1
#define IMAGE_TYPE_COL      2
#define IMAGE_TYPE_ART      4

typedef struct {
    unsigned char type;
    unsigned width, height;
    crypt_t crypt;
} image_t;

#endif

