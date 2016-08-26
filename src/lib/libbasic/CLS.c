
#include <basic.h>

void CLS(byte c)
{
    char s[] = "CLS?";
    s[3] = '0' + c;
    system(s);
}

