
#include <conio.h>
#include <string.h>

void cscrollup(void)
{
    memmove(1024, 1024 + 32, 32 * 15);
    memset(1024 + 32 * 15, 32, 32);
}

