
#include "_conio.h"

char putch(char c)
{
    if (isvidram()) {
        *(unsigned char*)_curpos = _conio.revers ? c & 63 : c & 63 | 64;
    } else {
        if (isgrpram()) {
            unsigned char* dst = (unsigned char*)_curpos;
            unsigned char horbyt = _horbyt;
            if (_conio.bgcolor) {
                unsigned char bits = _conio.fontpack ? _conio.fontbase & 128 ? 0xF : 0xF0 : 0xFF;
                *dst |= bits;
                dst += horbyt;
                *dst |= bits;
                dst += horbyt;
                *dst |= bits;
                dst += horbyt;
                *dst |= bits;
                dst += horbyt;
                *dst |= bits;
                dst += horbyt;
                *dst |= bits;
                dst += horbyt;
                *dst |= bits;
                dst += horbyt;
                *dst |= bits;
            } else {
                unsigned char bits = _conio.fontpack ? _conio.fontbase & 128 ? 0xF0 : 0xF : 0;
                *dst &= bits;
                dst += horbyt;
                *dst &= bits;
                dst += horbyt;
                *dst &= bits;
                dst += horbyt;
                *dst &= bits;
                dst += horbyt;
                *dst &= bits;
                dst += horbyt;
                *dst &= bits;
                dst += horbyt;
                *dst &= bits;
                dst += horbyt;
                *dst &= bits;
            }
            dst = (unsigned char*)_curpos;
            unsigned char* src = _conio.fontdata + (((unsigned)(c - 32) + _conio.fontbase) << 3);
            *dst ^= *src++;
            dst += horbyt;
            *dst ^= *src++;
            dst += horbyt;
            *dst ^= *src++;
            dst += horbyt;
            *dst ^= *src++;
            dst += horbyt;
            *dst ^= *src++;
            dst += horbyt;
            *dst ^= *src++;
            dst += horbyt;
            *dst ^= *src++;
            dst += horbyt;
            *dst ^= *src++;
        }
    }
    putrt();
    return c;
}

