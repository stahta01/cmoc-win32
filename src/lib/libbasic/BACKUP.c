
#include <basic.h>

int BACKUP(byte d)
{
    return systemf("BACKUP %d", d);
}

