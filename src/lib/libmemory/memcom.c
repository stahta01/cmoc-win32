
#include "_memory.h"

void asm _memcom(void* ptr, size_t n)
{
    asm {
        ldx     2,s
        beq     memcom_exit
        ldy     4,s
        beq     memcom_exit
        memcom_loop:
        com     ,x+
        leay    -1,y
        bne     memcom_loop
        memcom_exit:
    }
}

