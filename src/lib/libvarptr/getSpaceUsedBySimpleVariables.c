
#include "_varptr.h"

word getSpaceUsedBySimpleVariables()
{
    return * (char**) ARYTAB - * (char**) VARTAB;
}

