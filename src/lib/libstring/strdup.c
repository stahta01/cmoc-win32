
#include "_string.h"

char* strdup(const char* string)
{
    char* p;
    size_t slen;
    slen = strlen(string);
    p = (char*) malloc(slen + 1);
    strcpy(p, string);
    return (p);
}

