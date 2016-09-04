
/**************************************************************
 LZSS.H -- A Data Compression Program
***************************************************************
    4/6/1989 Haruhiko Okumura
    Use, distribute, and modify this program freely.
    Please send me your improved versions.
        PC-VAN      SCIENCE
        NIFTY-Serve PAF01022
        CompuServe  74050,1022

**************************************************************/

#ifndef _LZSS_H
#define _LZSS_H

int decompress_lzss(unsigned char* dst, unsigned char* src, unsigned srclen);

#endif

