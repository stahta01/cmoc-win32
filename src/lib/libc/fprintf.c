
#include <stdio.h>

int fprintf(FILE* fp, char* fmt, ...)
{
    int result = vsprintf(_stdbuf, fmt, (va_list)&fmt);
    fputs(_stdbuf, fp);
    return result;
}
