
#define enable _enable
#define disable _disable
#define enablef _enablef
#define disablef _disablef

void asm __ENABLE_ASM(void)
{
    asm {
#include "asm/ENABLE.ASM"
    }
}

