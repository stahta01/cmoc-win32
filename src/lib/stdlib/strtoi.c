
#include "_stdlib.h"

int strtoi(char* str, char** endptr, int base)
{
    int result = 0;
    char* pos = str;
    if (*pos == '+' || *pos == '-') {
        pos++;
    }
    if (!base) {
        if (*pos == '0') {
            pos++;
            if (*pos == 'x' || *pos == 'X') {
                base = 16;
                pos++;
            } else {
                base = 8;
            }
        }
    }
    for (; isdigit(*pos); pos++) {
        if (isdigit(*pos)) {
            result = result * base + (*pos - '0');
        } else if (islower(*pos)) {
            result = result * base + (*pos - 'a');
        } else if (isupper(*pos)) {
            result = result * base + (*pos - 'A');
        }
    }
    if (*str == '-') {
        result = -result;
    }
    if (endptr) {
        *endptr = pos;
    }
    return result;
}

