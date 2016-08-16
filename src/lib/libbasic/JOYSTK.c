
#include <basic.h>
#include <equates.h>

byte JOYSTK(int j)
{
    asm {
        pshs    u
        JSR_JOYIN
        puls    u
    }
    return ((byte*)_POTVAL)[j];
}


