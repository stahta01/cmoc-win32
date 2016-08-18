
// By Pierre Sarrazin <http://sarrazip.com/>.
// This file is in the public domain.
//
// Converted to C for WinCMOC by Derek Evans 2016

#include <string.h>

unsigned asm strlen(char* s)
{
    asm {
        pshs    x
        ldx     4,s

        strlen_010:
        tst     ,x+
        bne     strlen_010

        tfr     x,d
        subd    #1      // compensate for increment past '\0'
        subd    4,s     // substract start address
        puls    x,pc
    }
}

