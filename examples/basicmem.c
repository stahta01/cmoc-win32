
#pragma options -machine=coco

#include <stdio.h>
#include <equates.h>
#include <stdlib.h>
#include <string.h>

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

