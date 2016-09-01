
#include <conio.h>

int ungetch_buf = 0;

int ungetch(int c)
{
    if (ungetch_buf) {
        c = -1;
    } else {
        ungetch_buf = c;
    }
    return c;
}

