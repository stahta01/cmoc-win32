
#ifndef _RLE_H
#define _RLE_H

#include <sys/size.h>

byte* rle_decode(byte* dst, byte* src, size_t dstlen);
byte* rle_encode(byte* dst, byte* src, size_t srclen);

#endif

