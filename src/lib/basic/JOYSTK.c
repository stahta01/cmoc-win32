
#include "_basic.h"

byte JOYSTK(int j)
{
    system_joyin();
    return ((byte*)_POTVAL)[j];
}


