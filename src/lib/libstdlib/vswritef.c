
#include "_stdlib.h"

int vswritef(char* dst, char* fmt, va_list args)
{
    char* pos = dst;
    while (*fmt) {
        if ((*pos = *fmt++) == '%') {
            switch (*fmt++) {
            case 's':
                pos = _stpcpy(pos, (char*)*args++);
                break;
            case 'i':
            case 'd':
                pos = _strend(_itoa(*args++, pos));
                break;
            case 'u':
                pos = _strend(_utoa(*args++, pos));
                break;
            }
        } else {
            pos++;
        }
    }
    *pos = 0;
    return pos - dst;
}

