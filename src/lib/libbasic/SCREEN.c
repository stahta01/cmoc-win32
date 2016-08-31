
#include <basic.h>
#include <coco/cocodefs.h>

#include <equates.h>

void SCREENSETUP(void)
{
    byte mode, sect;
    if ((*(byte*)_PIA1BD) & 128) {
        sect = (*(byte*)_BEGGRP) >> 1;
        mode = _pmode + 3;
    } else {
        sect = 2;
        mode = 0;
    }
    ((byte*)_F0CLR)[(sect &  1) != 0] = true;
    ((byte*)_F1CLR)[(sect &  2) != 0] = true;
    ((byte*)_F2CLR)[(sect &  4) != 0] = true;
    ((byte*)_F3CLR)[(sect &  8) != 0] = true;
    ((byte*)_F4CLR)[(sect & 16) != 0] = true;
    ((byte*)_F5CLR)[(sect & 32) != 0] = true;
    ((byte*)_F6CLR)[(sect & 64) != 0] = true;

    byte v = _min(mode, 6);
    ((byte*)_V2CLR)[(v & 4) != 0] = true;
    ((byte*)_V1CLR)[(v & 2) != 0] = true;
    ((byte*)_V0CLR)[(v & 1) != 0] = true;

    mode <<= 4;
    (*(byte*)_PIA1BD) &= 0x8f;
    (*(byte*)_PIA1BD) |= mode;
}

void SCREEN(int mode, int css)
{
    systemf("SCREEN%d,%d", mode, css);
}

