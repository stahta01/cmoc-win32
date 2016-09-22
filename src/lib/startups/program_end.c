
#include <stdlib.h>

int heap_memory[2];

asm void _static_program_end(void)
{
    asm {
        program_end: export
        program_end:
    }
}


