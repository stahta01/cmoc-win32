
#include "_string.h"

int strmcmp(char* str, char* mem, size_t size)
{
    int result = strncmp(str, mem, size);
    return result ? result : str[size] ? (int)(str[size] - mem[size]) : 0;
}
