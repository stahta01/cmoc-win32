
#include "_eat.h"

char* eat_while_digit(char* str)
{
    return eat_while(str, isdigit);
}

