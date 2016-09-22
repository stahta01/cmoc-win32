
#pragma options -machine=coco

#include <stdio.h>

int main(void)
{
    FILE* fp = fopen("BASIC.TXT", "r");
    if (fp) {
        int c;
        for (;;) {
            printf("%4X", ftell(fp));
            c = fgetc(fp);
            if (c == EOF) {
                break;
            }
        }

        fclose(fp);
    }
    return 0;
}

