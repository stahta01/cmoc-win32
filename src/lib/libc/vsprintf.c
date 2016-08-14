
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vsprintf(char* dst, char* fmt, va_list args)
{
    int step = (va_list)&fmt - (va_list)&dst;
    char* s = dst;
    args += step;
    while (*fmt) {
        if (*fmt++ == '%') {
            switch (*fmt++) {
            case 'c':
                *s++ = (char)*args;
                args += step;
                break;
            case 's':
                s = stpcpy(s, (char*)*args);
                args += step;
                break;
            case 'o':
                s = strchr(itoa(*args, s, 8), 0);
                args += step;
                break;
            case 'd':
                s = strchr(itoa(*args, s, 10), 0);
                args += step;
                break;
            case 'x':
                s = strchr(itoa(*args, s, 16), 0);
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


