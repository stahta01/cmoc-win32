
#include <basic.h>

void* VARPTR(char* s)
{
    systemf("ZZ=VARPTR(%s)", s);
    return (void*)*(unsigned*)_varptr;
}

