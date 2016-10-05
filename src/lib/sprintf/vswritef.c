
#include "_sprintf.h"

int vswritef(char* str, char* fmt, va_list args)
{
    char* out = str;
    while (*fmt) {
        if ((*out = *fmt++) != '%') {
            out++;
        } else {
            switch (*fmt++) {
            default:
                out++;
                fmt--;
                break;
            case 'c':
                *out++ = (char)*args++;
                break;
            case 's':
                out = _stpcpy(out, (char*)*args++);
                break;
            case 'i':
            case 'd':
                out = _strend(_itoa(*args++, out));
                break;
            case 'u':
                out = _strend(_utoa(*args++, out));
                break;
            }
        }
    }
    *out = 0;
    return out - str;
}

