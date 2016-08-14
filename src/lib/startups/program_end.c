
#include <stdlib.h>

int heap_memory[100];

void asm __program_end(void)
{
    asm {
        program_end: export
        program_end:
    }
}


