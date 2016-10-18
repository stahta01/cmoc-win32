
#include "_coco.h"

void _setCaseFlag(byte upperCase)
{
    if (upperCase != 0) {
        upperCase = 0xFF;
    }
    *(byte*)0x11a = upperCase;
}

