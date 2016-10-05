
#include "_conio.h"

void _cputlf(void)
{
    cursormove(VT52_CHR_DOWN);
    gotox(0);
}

