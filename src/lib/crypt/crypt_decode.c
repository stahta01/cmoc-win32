
#include <crypt.h>
#include <string.h>
#include <lzss.h>
#include <exodecr.h>

void crypt_decode(crypt_t* crypt, void* dst, char* key)
{
    switch (crypt->type) {
    case CRYPT_TYPE_RAW:
        memcpy(dst, crypt + 1, crypt->dstsize);
        break;
    case CRYPT_TYPE_EXO:
        exo_decrunch((char*)(crypt + 1) + crypt->srcsize, (char*)dst + crypt->dstsize);
        break;
    case CRYPT_TYPE_LZSS:                       // 4096 ring buffer (1 << 12) = 4096
        decompress_lzss((unsigned char*)dst, (unsigned char*)(crypt + 1), crypt->srcsize);
        break;
    }
    if (key) {
        // TODO: Basic xor decryption
    }
}

