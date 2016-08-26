
#include <stdlib.h>

void CLS(unsigned char c)
{
    char s[] = "CLS?";
    s[3] = '0' + c;
    system(s);
}

