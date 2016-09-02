
#include "_conio.h"

unsigned char wherex(void)
{
    return isvidram() ? (unsigned char)(_curpos & 31) : (unsigned char)_gettextpositionx();
}

