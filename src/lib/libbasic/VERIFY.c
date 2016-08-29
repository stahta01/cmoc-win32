
#include <basic.h>

int VERIFY(byte onoff)
{
    return onoff ? VERIFY_ON() : VERIFY_OFF();
}

