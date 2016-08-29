
#include <basic.h>

int CLOSE(byte f)
{
    return systemf("CLOSE #%d", f);
}

