
#include "_malloc.h"

// allocates memory on the stack. also stores the memory size, so you
// can use _msize()

asm void* alloca(size_t size)
{
    asm {
        ldx     0,s                             // get return address
        ldy     2,s                             // get memory size
        tfr     s,d                             // adjust the stack by memory size
        subd    2,s
        subd    #2                              // include 2 bytes for memory size
        tfr     d,s
        stx     0,s                             // put back return address
        sty     4,s                             // put memory size
        addd    #6                              // return address + _alloca parameter + size value
    }
}

