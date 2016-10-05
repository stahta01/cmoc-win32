
#include "_graph.h"

void _setvideomode(int mode, int css)
{
    if (mode < 0) {
        systemf("SCREEN0,%d", css);
    } else {
        systemf("PMODE%d:SCREEN1,%d", mode < 4 ? mode : 4, css);
        _pmode = (byte)mode;
    }
}

