
#define enable      _enable
#define disable     _disable
#define enablef     _enablef
#define disablef    _disablef

asm void _static_(void)
{
    asm {
#include "asm/ENABLE.ASM"
    }
}

