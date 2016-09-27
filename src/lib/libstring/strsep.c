
#include "_string.h"

char* strsep(char** str, char* sep)
{
    char* s = *str, *end;
    if (!s) {
        return nullptr;
    }
    end = s + strcspn(s, sep);
    if (*end) {
        *end++ = 0;
    } else {
        end = 0;
    }
    *str = end;
    return s;
}

