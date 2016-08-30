
#include <stdlib.h>
#include <string.h>
#include <equates.h>

char* getenvstr(char* name, char* dst)
{
    systemf("ZZ=VARPTR(%s$)", name);
    memcpy(dst, (void*)((unsigned*)_varptr)[1], ((unsigned char*)_varptr)[0]);
    dst[((unsigned char*)_varptr)[0]] = 0;
    return dst;
}

