
#include "_varptr.h"

word _getSpaceUsedByProgram()
{
    return * (char**) VARTAB - * (char**) TXTTAB;
}

