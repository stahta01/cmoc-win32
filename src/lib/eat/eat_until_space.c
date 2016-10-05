
#include "_eat.h"

char* eat_until_space(char* str)
{
    return eat_until(str, isspace);
}

