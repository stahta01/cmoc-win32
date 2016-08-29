
#include <basic.h>

int main(void)
{
    char s[100];

    puts("Write out text file:");
    OPEN_O(1, "FILE");
    PRINT(1, "Welcome to the");
    PRINT(1, "TO THE COCO");
    CLOSE(1);

    if (OPEN_I(1, "FILE")) {
        INPUT(1, s);
        puts(s);
        INPUT(1, s);
        puts(s);
        INPUT(1, s);
        puts(s);
    }

    return 0;
}

