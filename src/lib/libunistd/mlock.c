
#include "_unistd.h"

unsigned _mlock_count = 0;

int mlock(void* addr, size_t len)
{
    if ((addr + len) >= 0x8000) {
        if (!_mlock_count) {
            asm {
                orcc    #$50    // disable irq and firq
                sta     $ffdf   // disable rom
            }
        }
        _mlock_count++;
    }
    return 0; // SUCCESS = 0
}

int munlock(void* addr, size_t len)
{
    if ((addr + len) >= 0x8000) {
        _mlock_count--;
        if (!_mlock_count) {
            asm {
                sta     $ffde   // enable rom
                andcc   #$af    // enable irq and firq
            }
        }
    }
    return 0; // SUCCESS = 0
}

