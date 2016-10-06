
#include "_graph.h"

void _setcharset(int packed, int base, byte* data)
{
    fontinfo.packed = (bool)packed;
    fontinfo.base = base;
    fontinfo.data = data;
}

