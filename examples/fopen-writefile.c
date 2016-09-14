
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

#include <equates.h>

int main(void)
{
    puts("WRITING FILE ...");
    FILE* fp = fopen("TEST.TXT", "w");
    if (fp) {
        fputs("THIS IS A TEST\n", fp);
        fputs("OF THE NEW CMOC STDIO.H\n", fp);
        fputs("FILE COMMANDS.\n", fp);
        fclose(fp);
    }
    puts("READING FILE ...");
    fp = fopen("TEST.TXT", "r");
    if (fp) {
        while (!feof(fp)) {
            char s[33];
            fgets(s, sizeof(s), fp);
            if (s[0] != '\r') {
                printf("> %s", s);
            }
        }
        fclose(fp);
    }

    puts("\n\nBACK TO BASIC");
    return 0;
}

