
#include "_graph.h"

void _setcharset(int type, int base, byte* data)
{
    fontinfo.type = (byte)type;
    fontinfo.base = (byte)base;
    fontinfo.data = data;
}

