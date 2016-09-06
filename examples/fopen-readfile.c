
#include <stdio.h>

int main(void)
{
    FILE* fp = fopen("BASIC.TXT", "r");
    if (fp) {
        while (!feof(fp)) {
            printf("%c", fgetc(fp));
        }
        fclose(fp);
    }
    return 0;
}

