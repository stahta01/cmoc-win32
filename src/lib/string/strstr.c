
#include "_string.h"

char* strstr(char* string1, char* string2)
{
    char* p1, *p2, *p3;
    int found = 0;
    while (*string1 && !found) {
        p1 = string1;
        p2 = string2;
        p3 = nullptr;
        found = 1;
        while (*p2) {
            if (*p1 != *p2) {
                found = 0;
                break;
            } else {
                p1++;
                p2++;
            }
        }
        if (!found) {
            string1++;
        } else {
            p3 = string1;
        }
    }
    return p3;
}

