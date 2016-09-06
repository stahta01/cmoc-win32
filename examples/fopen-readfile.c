
#include <stdio.h>
#include <string.h>
#include <conio.h>

int main(void)
{
    FILE* fp;
    /*
    fp = fopen("BASIC.TXT", "r");
    if (fp) {
        while (!feof(fp)) {
            printf("%d*", fgetc(fp));
        }
        fclose(fp);
    }
    */
    fp = fopen("BASIC.TXT", "r");
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

    return 0;
}

