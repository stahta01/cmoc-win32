
#include "_system.h"

void system_fputs(char* str)
{
    for (char chr; chr = *str++;) {
        asm {
            lda     :chr
            jsr     [handle_fputc]
        }
    }
}

