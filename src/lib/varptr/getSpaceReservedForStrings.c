
#include "_varptr.h"

word _getSpaceReservedForStrings()
{
    return * (char**) MEMSIZ - * (char**) FRETOP;
}

