
#include <fcntl.h>

int creat(char* name, unsigned mode)
{
    return open(name, O_WRONLY | O_CREAT | O_TRUNC, mode);
}

