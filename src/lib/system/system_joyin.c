
#include "_system.h"

asm void system_joyin(void)
{
    asm_jsr_basic([handle_joyin]);
}

