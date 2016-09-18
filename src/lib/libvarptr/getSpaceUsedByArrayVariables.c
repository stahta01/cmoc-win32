
#include "_varptr.h"

word _getSpaceUsedByArrayVariables()
{
    return * (char**) ARYEND - * (char**) ARYTAB;
}

