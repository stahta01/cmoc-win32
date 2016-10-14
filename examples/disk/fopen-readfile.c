
// Requires coco2b for lower case letters
#pragma options -machine=coco2b

#include <stdio.h>
#include <string.h>
#include <conio.h>

int main(void)
{
    *(byte*)0xff22 |= 16;                           // lower case letters
    puts("READING FILE ...");
    FILE* fp = fopen("BASIC.TXT:1", "r");
    if (fp) {
        while (!feof(fp)) {
            char s[33];
            fgets(s, sizeof(s), fp);
            if (s[0] != '\r') {
                fputs(s, stdout);
            }
        }
        fclose(fp);
    }
    puts("\n\nBACK TO BASIC");
    return 0;
}

