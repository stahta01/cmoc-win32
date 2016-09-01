
#include <conio.h>

int ungetch_buf;

int ungetch(int c)
{
    if (ungetch_buf) {
        c = -1;
    } else {
        ungetch_buf = c;
    }
    return c;
}

