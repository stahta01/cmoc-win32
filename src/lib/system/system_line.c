
#include "_system.h"

asm void system_line(void)
{
    asm_jsr_basic([handle_line]);
}

