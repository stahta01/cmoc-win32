
#include <motorola.h>

void MotorolaSetSAM(byte section)
{
    for (byte bit = 0; bit < 7; bit++) {
        ((byte*)65478 + (bit << 1))[section & 1] = TRUE;
        section >>= 1;
    }
}


