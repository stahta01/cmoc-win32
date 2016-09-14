
#ifndef _CRYPT_H
#define _CRYPT_H

#define CRYPT_TYPE_RAW   0
#define CRYPT_TYPE_EXO   1
#define CRYPT_TYPE_LZSS  12

typedef struct {
    unsigned char type;
    unsigned dstsize, srcsize;
} crypt_t;

void crypt_decode(crypt_t* crypt, void* dst, char* key);

#endif

