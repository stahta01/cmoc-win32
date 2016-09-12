
#define strncmp __obsolete

#include "_string.h"

int strncmp(char* string1, char* string2, size_t count)
{
    int result = 0;
    while ((*string1 == *string2) && (count > 1)) {
        count--;
        if (!(*string1) || !(*string2)) {
            count = 0;
        } else {
            string1++;
            string2++;
        }
    }
    result = 0;
    if (*string1 > *string2) {
        result = 1;
    } else {
        if (*string1 < *string2) {
            result = -1;
        }
    }
    return (result);
}

