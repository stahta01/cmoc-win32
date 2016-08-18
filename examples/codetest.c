
#include <stdio.h>

void test1(void)
{
    int i;
    unsigned char b;
    b = *(((unsigned char*)&i)+1);
}

void test2(void)
{
    int i;
    char b;
    b = (char)i;
}

int main(void)
{
    return 0;
}

