
// This demo only works for pre-coco2b machines.
// Go figure!

#pragma options -machine=coco

#include <stdio.h>
#include <conio.h>
#include <charset.h>

int main(void)
{
    char s[100];

    // We use textmode2, because we need the charset_6x8 (which isn't the default),
    // and this way the default charset's are not linked into the binary.

    textmode2(MODE_H0_32X24, charset_6x8);

    // Remove this line to use standard pmode 4
    *(unsigned char*)0xff22 &= 127;

    s[0] = 0;
    while (s[0] != 'x' && s[0] != 'X') {
        puts("Bitmap Graphics on Text!");
        puts("This is a demo of a relatively");
        puts("unknown graphics mode of the");
        puts("CoCo 2. It is limited to blocks");
        puts("of 6 pixels in width. This is");
        puts("because bit7 is used for semi");
        puts("chars, and bit6 is used for");
        puts("reverse. So, bits 0..5, can be");
        puts("used for text.");
        puts("\nPlease try the editor (x=Exit)");
        gets(s);
        *(unsigned char*)0xff22 ^= 8;
    }

    textmode2(0, 0);
    puts("BACK TO BASIC");

    return 0;
}
