
// Simple example of using sscanf. This code is new, so it is still undergoing bug checking.
// Please contact me if you find an issue.

#include <conio.h>
#include <string.h>
#include <stdio.h>

int main(void)
{
    char* src = "    COCO   NUMBER=-1234  COUNT=100 40000ABC (123)";
    char s[10], a, b, c;
    int i1, i2, i3;
    unsigned u;
    cprintf("COUNT: %d\n",
            sscanf(src, "%s NUMBER=%i COUNT=%i%u%c%c%c (%d)", s, &i1, &i2, &u, &a, &b, &c, &i3));
    cprintf("%s,%i,%i,%u,%c,%c,%c,%d\n", s, i1, i2, u, a, b, c, i3);

    return 0;
}

