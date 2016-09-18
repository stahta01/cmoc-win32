
#include "_varptr.h"

word _getSpaceUsedBySimpleVariables()
{
    return * (char**) ARYTAB - * (char**) VARTAB;
}

