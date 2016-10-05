
#include "_eat.h"

char* eat_while_space(char* str)
{
    return eat_while(str, isspace);
}

