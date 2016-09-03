
#include "_varptr.h"

word getSpaceUsedByProgram()
{
    return * (char**) VARTAB - * (char**) TXTTAB;
}

