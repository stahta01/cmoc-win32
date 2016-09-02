
#include "_graph.h"

void _setcharset(int type, int base, unsigned char* data)
{
    fontinfo.type = (char)type;
    fontinfo.base = (char)base;
    fontinfo.data = data;
}

