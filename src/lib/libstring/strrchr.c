
#include "_string.h"

char* strrchr(char* string, int c)
{
    char* p = NULL;
    while (*string) {
        if ((int)(*string) == c) {
            p = (char*)string;
        }
        string++;
    }
    return (p);
}

