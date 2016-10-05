
#include <motorola.h>

void MotorolaSetVDG(byte section, word mode)
{
    byte i, *p;
    p = (byte*)65478;
    for (i = 0; i < 7; i++, p += 2) {
        p[section & 1] = TRUE;
        section >>= 1;
    }
    p = (byte*)65472;
    for (i = 0; i < 3; i++, p += 2) {
        p[_LOBYTE(mode) & 1] = TRUE;
        _LOBYTE(mode) >>= 1;
    }
    *(byte*)(65314) = (*(byte*)(65314) & 7) | (_HIBYTE(mode) << 3);
}


