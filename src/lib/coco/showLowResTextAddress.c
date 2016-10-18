
#include "_coco.h"

// Select the 32x16 text mode and position the screen buffer at address 1024.
//
void _showLowResTextAddress()
{
    _setSAMRegisters((byte*)0xFFC6, 2, 7);         // 2 == 0x0400 / 512
    _setSAMRegisters((byte*)0xFFC0, 0, 3);         // 0 == 32x16 mode
}

