
#include <stdio.h>
#include <equates.h>

int main(void)
{
    _execjp = 0x2800;

    printf("PROGRAM    : %d\n", _txttab);
    printf("VARIABLES  : %d\n", _vartab);
    printf("ARRAYS     : %d-%d\n", _arytab, _aryend);
    printf("STRING MEM : %d\n", _fretop);
    printf("STRINGS    : %d-%d\n",  _strtab, _memsiz);
    printf("MEMSIZE    : %d\n", _memsiz);

    return 0;
}

