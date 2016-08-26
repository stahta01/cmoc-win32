
#include <basic.h>

void PCLS(byte c)
{
    char s[] = "PCLS?";
    s[4] = '0' + c;
    system(s);
}

