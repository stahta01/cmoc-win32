
#include "_conio.h"

void scrclr(void)
{
    if (isvidram()) {
        memset(_VIDRAM, 96, 0x200);
    } else {
        if (_conio.clearscreen) {
            _conio.clearscreen(_GCLEARSCREEN);
        }
    }
}

