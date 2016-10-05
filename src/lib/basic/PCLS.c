
#include <basic.h>

void PCLS(int c)
{
    char s[] = "PCLS?";
    s[4] = '0' + c;
    system(s);
}

