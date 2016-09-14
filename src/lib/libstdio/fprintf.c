
#include "_stdio.h"

int fprintf(FILE* fp, char* fmt, ...)
{
    char buf[BUFSIZ];
    int result = vsprintf(buf, fmt, (va_list)&fmt);
    fputs(buf, fp);
    return result;
}
