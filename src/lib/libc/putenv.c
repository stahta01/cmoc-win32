
#include "_libc.h"

int putenv(char* envptr)
{
    char* p = strchr(envptr, '=');
    if (p) {
        char c = *p;
        *p = 0;
        putenvstr(envptr, p + 1);
        *p = c;
    }
    return 0;
}

