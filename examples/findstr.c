
// findstr tests.
// note: the pattern does not support wild cards and is case sensitive.

#include <os9.h>
#include <conio.h>

void test(int pos, char* str, char* pat)
{
    cprintf("(pos=%d pat='%s')=%d\n", pos, pat, _findstr(pos, str, pat));
}

int main(void)
{
    char* str = "CMOC Compiler!";
    *(byte*)0xff22 |= 16;
    clrscr();
    cputs("kreider's findstr() tests\n");
    cprintf("String='%s'\n\n", str);
    test(1, str, "Compiler");
    test(1, str, "compiler");
    test(1, str, "MOC");
    test(5, str, "CMOC");
    test(1, str, "er");
    test(1, str, "C");
    test(1, str, "!");
    cputs("\nBACK TO BASIC\n");
    return 0;
}

