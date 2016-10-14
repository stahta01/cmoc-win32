
#include "_basic.h"

void* VARPTR(char* s)
{
    systemf("ZZ=VARPTR(%s)", s);
    return (void*)*(word*)_varptr;
}

