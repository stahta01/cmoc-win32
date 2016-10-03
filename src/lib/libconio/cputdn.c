
#include "_conio.h"

void _cputdn(void)
{
    if (isvidram()) {
        _curpos += 32;
        if (!isvidram()) {
            _curpos -= 32;
            scrup();
        }
    } else {
        if (isgrpram()) {
            unsigned line = (unsigned)_horbyt << 3;
            _curpos += line;
            if (!isgrpram()) {
                _curpos -= line;
                scrup();
            }
        }
    }
}

