
#include "_eat.h"

char* eat_integer(char* str)
{
    return eat_while_digit(eat_sign(str));
}

