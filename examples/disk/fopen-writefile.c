
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <system.h>

int main(void)
{
    puts("STDIO EXAMPLE");
    FILE* fp = fopen("TEST.TXT", "w");
    if (fp) {
        puts("WRITING FILE ...");
        fputs("THIS IS A TEST\n", fp);
        fputs("OF THE NEW CMOC STDIO.H\n", fp);
        fputs("FILE COMMANDS.", fp);
        fclose(fp);
    }
    fp = fopen("TEST.TXT", "r");
    if (fp) {
        puts("READING FILE ...");
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

