
#include "_eat.h"

char* eat_while_xdigit(char* str)
{
    return eat_while(str, isxdigit);
}

