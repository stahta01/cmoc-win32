
#include "_eddie.h"

int eddie_line(char* str, size_t size, char* eolchars, bool leaveatend)
{
    *str = 0;
    return eddie_line_at(str, size, whereat(), 0, eolchars, leaveatend);
}

