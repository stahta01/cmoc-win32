
#include <basic.h>

int VERIFY(int onoff)
{
    return onoff ? VERIFY_ON() : VERIFY_OFF();
}

