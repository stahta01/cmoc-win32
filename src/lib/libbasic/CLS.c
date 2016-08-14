
#include <basic.h>
#include <string.h>

void CLS(byte c)
{
    memset((void*)0x400, c ? 0x8F | ((c - 1) << 4) : 0x80, 512);
}

