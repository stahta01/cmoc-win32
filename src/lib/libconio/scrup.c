
#include "_conio.h"

void scrup(void)
{
    if (isvidram()) {
        memmove(_VIDRAM, _VIDRAM + 32, 32 * 15);
        memset(_VIDRAM + 32 * 15, 96, 32);
    } else {
        if (isgrpram()) {
            _scrolltextwindow(_GSCROLLUP);
        }
    }
}

