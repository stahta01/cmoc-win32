
#include "_string.h"

word _static_strerror[2];

char* strerror(errno_t error)
{
    _static_strerror[0] = *(word*)((error < ERRNO_UF ? _LABAF : _L890B - ERRNO_UF) + error);
    _static_strerror[1] = 0;
    return (char*)_static_strerror;
}

