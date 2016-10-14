
#include "_basic.h"

int DRIVE(int d)
{
    return systemf("DRIVE%d", d);
}

