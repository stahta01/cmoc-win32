
#ifndef _CRYPT_IMAGE_H
#define _CRYPT_IMAGE_H

#include <crypt.h>

#define CRYPT_IMAGE_TYPE_CSS      1
#define CRYPT_IMAGE_TYPE_COL      2
#define CRYPT_IMAGE_TYPE_ART      4

typedef struct {
    unsigned char type;
    unsigned width, height;
    crypt_t crypt;
} crypt_image_t;

#endif

