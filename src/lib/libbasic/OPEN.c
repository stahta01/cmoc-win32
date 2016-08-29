
#include <basic.h>

int OPEN(char mode, byte f, char* fn, size_t len)
{
    return systemf(len ? "OPEN \"%c\",%u,\"%s\",%u" : "OPEN \"%c\",%u,\"%s\"", toupper(mode), f, fn,
                   len);
}

