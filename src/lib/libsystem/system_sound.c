
#include "_system.h"

asm void system_sound(void)
{
    asm_jsr_basic([handle_sound]);
}

