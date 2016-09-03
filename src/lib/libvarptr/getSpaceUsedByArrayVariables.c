
#include "_varptr.h"

word getSpaceUsedByArrayVariables()
{
    return * (char**) ARYEND - * (char**) ARYTAB;
}

