
#include "_varptr.h"

word getSpaceReservedForStrings()
{
    return * (char**) MEMSIZ - * (char**) FRETOP;
}

