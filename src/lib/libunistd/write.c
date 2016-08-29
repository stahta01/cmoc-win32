
#include <fcntl.h>
#include <stdlib.h>

// Doesn't support \0 characters.

int write(int fd, void* buf, unsigned count)
{
    char c = ((char*)buf)[count];
    ((char*)buf)[count] = 0;
    int err = systemf("PRINT #%d,\"%s\";", fd, buf);
    ((char*)buf)[count] = c;
    return err;
}

