
#include "_sprintf.h"

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
    } else {
        if (dst != src) {
            dst = (char*)memcpy(dst, src, srclen);
        }
        for (dst += srclen, width += srclen; width++ < 0; *dst++ = padchar);
    }
    return dst;
}

int vsprintf(char* str, char* fmt, va_list args)
{
    char* out = str;
    while (*fmt) {
        if ((*out = *fmt++) != '%') {
            out++;
        } else {
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
            char input_size = *fmt;
            if (input_size == 'F' || input_size == 'N' || input_size == 'l' || input_size == 'h') {
                fmt++;
            }
            switch (*fmt++) {
            default:
                out++;
                fmt--;
                break;
            case 'c':
                *out++ = (char)*args++;
                break;
            case 's':
                if (input_size == 'F') {
                    out = strpcpy_pad(out, (char*)far_zoom((far_void_t*)*args), width, padchar);
                    far_zoom((far_void_t*)*args++);
                } else {
                    out = strpcpy_pad(out, (char*)*args++, width, padchar);
                }
                break;
            case 'd':
            case 'i':
                if (input_size == 'l') {
                    out = strpcpy_pad(out, _ltoa((long_t*)*args++, out), width, padchar);
                } else {
                    out = strpcpy_pad(out, _itoa(*args++, out), width, padchar);
                }
                break;
            case 'o':
                out = strpcpy_pad(out, utoa(*args++, out, 8), width, padchar);
                break;
            case 'x':
                out = strpcpy_pad(out, utoa(*args++, out, 16), width, padchar);
                break;
            case 'X':
                out = strpcpy_pad(out, _strupr(utoa(*args++, out, 16)), width, padchar);
                break;
            case 'p':
                // This isn't correct, but it will do for now.
                out = strpcpy_pad(out, _strupr(utoa(*args++, out, 16)), 4, '0');
                break;
            case 'u':
                out = strpcpy_pad(out, _utoa(*args++, out), width, padchar);
                break;
            case 'f':
                out = strpcpy_pad(out, _ftoa((float_t*)*args++, out), width, padchar);
                break;
            }
        }
    }
    *out = 0;
    return out - str;
}

