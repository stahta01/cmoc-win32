
#include "_eddie.h"

int eddie_line(char* str, size_t size, char* eolchars, bool leaveatend)
{
    *str = 0;
    size_t at = whereat(), xy = at;
    int chr;
    while (!strchr(eolchars, chr = eddie_line_at(str, size, &at, &xy, eolchars)));
    if (leaveatend) {
        gotoat(at + strlen(str));
    }
    return chr;
}

