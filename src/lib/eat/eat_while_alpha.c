
#include "_eat.h"

char* eat_while_alpha(char* str)
{
    return eat_while(str, isalpha);
}

