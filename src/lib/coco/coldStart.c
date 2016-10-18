
#include "_coco.h"

void _coldStart(void)
{
    asm("CLR", "$71");                              // POKE 113,0
    asm("JMP", "$A027");                            // EXEC 40999
}

