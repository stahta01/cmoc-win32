
#include "_system.h"

int system_waitkey(bool blink)
{
    byte key;
    if (blink) {
        asm {
            jsr     _LA1B1
            sta     key
        }
    } else {
        do {
            asm {
                jsr     [$a000]
                sta     key
            }
        } while (!key);
    }
    return key;
}

