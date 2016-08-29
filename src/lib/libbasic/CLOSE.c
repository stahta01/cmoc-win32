
#include <basic.h>
#include <fcntl.h>

int CLOSE(int fd)
{
    // Dont call close(). We do not alloc FileDesc's
    return systemf("CLOSE #%d", fd);
}

