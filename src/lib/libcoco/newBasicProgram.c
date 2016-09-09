
#include "_coco.h"

// Calls BASIC's NEW command.
//
void newBasicProgram()
{
    asm("PSHS", "U,Y");                     // protect against BASIC routine
    asm("JSR", "$AD19");
    asm("PULS", "Y,U");
}

