
#include "_basic.h"

int BACKUP2(int d1, int d2)
{
    return systemf("BACKUP %d TO %d", d1, d2);
}

