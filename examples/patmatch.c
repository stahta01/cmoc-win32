
#include <os9.h>
#include <conio.h>

void test(char* pat, char* str, bool ignorecase)
{
    cprintf("(\"%s\"==\"%s\")=%s\n", str, pat, _patmatch(pat, str, ignorecase) ? "TRUE" : "FALSE");
}

int main(void)
{
    *(byte*)0xff22 |= 16;
    clrscr();
    cputs("kreider's patmatch() tests\n");
    test("a*", "Apple", true);
    test("??o?", "cmoc", true);
    test("??o?", "not cmoc", true);
    test("A*", "android", false);
    test("*land*", "zoolander", false);
    test("leax *,y", "LEAX 10,y", true);
    test("*.jpeg", "image.bmp", true);
    test("*.jp?g", "image.jpeg", true);
    test("$????", "$56ad", true);
    test("'*'", "quoted?", true);
    test("'*'", "'quoted?'", true);
    test("(*)", "(brackets?)", true);
    cputs("\nBACK TO BASIC");
    return 0;
}

