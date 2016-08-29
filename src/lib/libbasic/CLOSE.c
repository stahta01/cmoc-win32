
#include <basic.h>

int CLOSE(int f)
{
    return systemf("CLOSE #%d", f);
}

