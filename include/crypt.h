
#ifndef _CRYPT_H
#define _CRYPT_H

typedef struct {
    unsigned char type;
    unsigned dstsize, srcsize;
} crypt_t;

void crypt_decode(crypt_t* crypt, void* dst, char* key);

#endif

