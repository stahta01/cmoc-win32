
#include "_libc.h"

#include <far.h>

char* strpcpy_pad(char* dst, char* src, int width, char padchar)
{
    int srclen = strlen(src);
    if (width > srclen) {
        width -= srclen;
        memmove(dst + width, src, srclen);
        while (width--) {
            *dst++ = padchar;
        }
        dst += srclen;
    } else if (width < 0) {
        dst = (char*)memcpy(dst, src, srclen) + srclen;
        for (width += srclen; width++ < 0; *dst++ = padchar);
    } else {
        dst = (char*)memcpy(dst, src, srclen) + srclen;
    }
    return dst;
}

int vsprintf(char* dst, char* fmt, va_list args)
{
    char* pos = dst;
    while (*fmt) {
        if (*fmt++ == '%') {
            char isneg = *fmt == '-';
            if (isneg) {
                fmt++;
            }
            char padchar = ' ';
            if (*fmt == '0') {
                padchar = '0';
                fmt++;
            }
            int width = 0;
            while (_isdigit(*fmt)) {
                width = width * 10 + (*fmt++ - '0');
            }
            if (isneg) {
                width = -width;
            }
            if (*fmt == 'F' || *fmt == 'N') {
                fmt++;
            }
            switch (*fmt++) {
            case 'c':
                *pos++ = (char)*args++;
                break;
            case 's':
                if (fmt[-2] == 'F') {
                    pos = strpcpy_pad(pos, (char*)far_zoom((far_void_t*)*args), width, padchar);
                    far_zoom((far_void_t*)*args++);
                } else {
                    pos = strpcpy_pad(pos, (char*)*args++, width, padchar);
                }
                break;
            case 'd':
            case 'i':
                pos = strpcpy_pad(pos, itoa(*args++, pos, 10), width, padchar);
                break;
            case 'o':
                pos = strpcpy_pad(pos, utoa(*args++, pos, 8), width, padchar);
                break;
            case 'x':
                pos = strpcpy_pad(pos, utoa(*args++, pos, 16), width, padchar);
                break;
            case 'X':
                pos = strpcpy_pad(pos, _strupr(utoa(*args++, pos, 16)), width, padchar);
                break;
            case 'p':
                // This isn't correct, but it will do for now.
                pos = strpcpy_pad(pos, _strupr(utoa(*args++, pos, 16)), 4, '0');
                break;
            case 'u':
                pos = strpcpy_pad(pos, utoa(*args++, pos, 10), width, padchar);
                break;
            case 'f':
                pos = strpcpy_pad(pos, _ftoa(pos, (float_t*)*args++), width, padchar);
                break;
            default:
                *pos++ = fmt[-1];
                break;
            }
        } else {
            *pos++ = fmt[-1];
        }
    }
    *pos = 0;
    return pos - dst;
}

