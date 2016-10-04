
#include "_string.h"

int strtoi(char* s, char** endptr, int radix)
{
    char sign = 0;
    int value = 0;
    for (; _isspace(*s); s++);
    if ((*s == '-') || (*s == '+')) {
        sign = *s;
        s++;
    }
    if (s[0] == '0' && s[1] == 'x') {
        s += 2;
        if (!radix) {
            radix= 16;
        }
    } else {
        if (!radix) {
            radix = 10;
        }
    }
    for (; *s; s++) {
        char c = *s;
        c = _isdigit(c) ? c - '0' : _tolower(c) - 'a' + 10;
        if (c >= 0 && c < radix) {
            value = value * radix + c;
        } else {
            break;
        }
    }
    if (endptr) {
        *endptr = s;
    }
    return sign == '-' ? -value : value;
}

