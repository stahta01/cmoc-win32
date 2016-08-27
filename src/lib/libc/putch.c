
#include "_conio.h"

char putch(char c)
{
    if (isvidram()) {
        *(unsigned char*)_curpos = _conio.revers ? c & 63 : c & 63 | 64;
    } else {
        if (isgrpram()) {
            unsigned char* dst = (unsigned char*)_curpos;
            unsigned char* src = _conio.fontdata + (((unsigned)c + _conio.fontbase) << 3);
            *dst ^= *src++;
            dst += _horbyt;
            *dst ^= *src++;
            dst += _horbyt;
            *dst ^= *src++;
            dst += _horbyt;
            *dst ^= *src++;
            dst += _horbyt;
            *dst ^= *src++;
            dst += _horbyt;
            *dst ^= *src++;
            dst += _horbyt;
            *dst ^= *src++;
            dst += _horbyt;
            *dst ^= *src++;
            dst += _horbyt;
        }
    }
    putrt();
    return c;
}

