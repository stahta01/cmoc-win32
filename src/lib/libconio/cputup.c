
#include "_conio.h"

void _cputup(void)
{
    if (isvidram()) {
        _curpos -= 32;
        if (!isvidram()) {
            _curpos += 32;
        }
    } else {
        if (isgrpram()) {
            unsigned line = (unsigned)_horbyt << 3;
            _curpos -= line;
            if (!isgrpram()) {
                _curpos += line;
            }
        }
    }
}

