
#include <basic.h>

int OPEN(char mode, int f, char* fn, size_t len)
{
    return systemf(len ? "OPEN \"%c\",#%d,\"%s\",%u" : "OPEN \"%c\",#%d,\"%s\"", toupper(mode), f, fn,
                   len);
}

