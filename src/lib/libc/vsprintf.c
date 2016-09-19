
#include "_libc.h"

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
    int step = (va_list)&fmt - (va_list)&dst;
    char* s = dst;
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
            switch (*fmt++) {
            case 'c':
                *s++ = (char)*args;
                args += step;
                break;
            case 's':
                s = strpcpy_pad(s, (char*)*args, width, padchar);
                args += step;
                break;
            case 'd':
                s = strpcpy_pad(s, itoa(*args, s, 10), width, padchar);
                args += step;
                break;
            case 'o':
                s = strpcpy_pad(s, utoa(*args, s, 8), width, padchar);
                args += step;
                break;
            case 'x':
                s = strpcpy_pad(s, strlwr(utoa(*args, s, 16)), width, padchar);
                args += step;
                break;
            case 'X':
                s = strpcpy_pad(s, utoa(*args, s, 16), width, padchar);
                args += step;
                break;
            case 'u':
                s = strpcpy_pad(s, utoa(*args, s, 10), width, padchar);
                args += step;
                break;
            case 'f':
                s = strpcpy_pad(s, _ftoa(s, (float_t*)*args), width, padchar);
                args += step;
                break;
            default:
                *s++ = fmt[-1];
                break;
            }
        } else {
            *s++ = fmt[-1];
        }
    }
    *s = 0;
    return s - dst;
}

