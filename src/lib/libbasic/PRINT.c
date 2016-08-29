
#include <basic.h>

int PRINT(int f, char* fmt, ...)
{
    char s[BUFSIZ];
    vsprintf(s, fmt, (va_list)&fmt);
    return systemf("PRINT #%d,\"%s\"", f, s);
}

