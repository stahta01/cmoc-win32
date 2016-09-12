
#include "_string.h"

size_t strcspn(char* string1, char* string2)
{
    char* p;
    size_t pos = 0;
    short found = 0;
    while (*string1 && (!found)) {
        p = (char*)string2;
        while (*p) {
            if (*string1 == *p) {
                found = 1;
                break;
            }
            p++;
        }
        if (!found) {
            pos++;
            string1++;
        }
    }
    return (pos);
}

