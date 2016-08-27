
#include "_conio.h"

char putch(char c)
{
    if (isvidram()) {
        *(unsigned char*)_curpos = _conio.revers ? c & 63 : c & 63 | 64;
    } else {
        if (isgrpram()) {
            unsigned char set = _conio.fontpack ? _conio.fontbase & 128 ? 0xF : 0xF0 : 0xFF;
            unsigned char* dst = (unsigned char*)_curpos;
            *dst |= set;
            dst += _horbyt;
            *dst |= set;
            dst += _horbyt;
            *dst |= set;
            dst += _horbyt;
            *dst |= set;
            dst += _horbyt;
            *dst |= set;
            dst += _horbyt;
            *dst |= set;
            dst += _horbyt;
            *dst |= set;
            dst += _horbyt;
            *dst |= set;
            dst = (unsigned char*)_curpos;
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
        }
    }
    putrt();
    return c;
}

