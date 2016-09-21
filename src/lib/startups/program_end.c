
#include <stdlib.h>

int heap_memory[2];

void asm __program_end(void)
{
    asm {
        program_end: export
        program_end:
    }
}


