
#include "_basic.h"

byte JOYSTK(int j)
{
    joyin();
    return ((byte*)_POTVAL)[j];
}


