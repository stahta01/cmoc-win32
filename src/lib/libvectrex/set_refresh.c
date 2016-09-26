
#include <vectrex.h>

void vectrex_set_refresh(uint16_t value)
{
    asm {
        JSR     DP_to_D0
        LDX     value
        STX     0xc83e
        PSHS    D
        JSR     Set_Refresh
        PULS    D
    }
}




