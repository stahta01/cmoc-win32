
#include <stdlib.h>

void PCLS(unsigned char c)
{
    char s[] = "PCLS?";
    s[4] = '0' + c;
    system(s);
}





