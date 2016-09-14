
// Requires coco2b for lower case letters
#pragma options -machine=coco2b

#include <stdio.h>
#include <string.h>
#include <conio.h>

int main(void)
{
    *(unsigned char*)65314 |= 16;
    puts("READING FILE ...");
    FILE* fp = fopen("BASIC.TXT", "r");
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

