
#include <basic.h>

void PMODE(int mode, int page)
{
    char s[] = "PMODE?,?";
    s[5] = '0' + (char)mode;
    s[7] = '0' + (char)page;
    system(s);
}

