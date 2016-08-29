
#include <unistd.h>
#include <stdio.h>

int unlink(char* fn)
{
    return remove(fn);
}

