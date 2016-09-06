
#include "_stdio.h"

int fprintf(FILE* fp, char* fmt, ...)
{
    char s[BUFSIZ];
    int result = vsprintf(s, fmt, (va_list)&fmt);
    fputs(s, fp);
    return result;
}
