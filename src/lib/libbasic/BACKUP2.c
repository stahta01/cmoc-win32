
#include <basic.h>

int BACKUP2(byte d1, byte d2)
{
    return systemf("BACKUP %d TO %d", d1, d2);
}

