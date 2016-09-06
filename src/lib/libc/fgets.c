
#include "_libc.h"

char* fgets(char* s, size_t n, FILE* fp)
{
    if (fp) {
        return NULL;
    } else {
        // Since char is signed, the max for cgets is most
        // likely 126-ish.
        s[0] = n < 100 ? (char)n : 100;
        strcpy(s, cgets(s));
        cputc('\n');
        return s;
    }
}

