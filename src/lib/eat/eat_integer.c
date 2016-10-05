
#include "_eat.h"

char* eat_integer(char* str)
{
    return eat_while(eat_sign(str), isdigit);
}

