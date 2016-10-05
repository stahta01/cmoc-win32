
#include "_disk.h"

void asm _setOutputDevice(sbyte deviceNum)
{
    asm {
        ldb     3,s     // deviceNum
        stb     $6F     // Color Basic's DEVNUM
    }
}



