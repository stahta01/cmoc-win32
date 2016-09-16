
#pragma options -machine=coco

#include <stdio.h>
#include <equates.h>
#include <stdlib.h>
#include <string.h>
#include <system.h>


int _system(void)
{
    asm {
        pshs    u
        ldx     #-1                             // Was -1
        stx     _CURLIN
        ldx     #_LINBUF
        stx     _CHARAD
        jsr     _GETNCH
        jsr     [sysptr_crunch]
        jsr     _GETNCH
        jsr     [sysptr_execute]
        puls    u
    }
    return 0;
}

int system(char* cmd)
{
    strcpy(SYSTEM_CMDLINE, cmd);
    return _system();
}

int systemf(char* fmt, ...)
{
    vsprintf(SYSTEM_CMDLINE, fmt, (va_list)&fmt);
    return _system();
}

int main(void)
{
    _execjp = 0x2800;

    //_strtab = _memsiz = _execjp - 1;
    //_fretop = _strtab - 256;

    printf("PROGRAM    : %d\n", _txttab);
    printf("VARIABLES  : %d\n", _vartab);
    printf("ARRAYS     : %d-%d\n", _arytab, _aryend);
    printf("STRING MEM : %d\n", _fretop);
    printf("STRINGS    : %d-%d\n",  _strtab, _memsiz);
    printf("MEMSIZE    : %d\n", _memsiz);

    return 0;
}

