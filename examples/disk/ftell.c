
#pragma options -machine=coco

#include <stdio.h>
#include <conio.h>

int main(void)
{
    clrscr();
    cputs("LOADING FILE ...\n");
    FILE* fp = fopen("ALPHA.TXT:1", "r");
    cprintf("FILE SIZE: %d BYTES\n", _fsize(fp));
    cputs("READING FILE ...\n");
    if (fp) {
        for (int c; (c = fgetc(fp)) != EOF;) {
            cprintf("%2d%c ", ftell(fp), c);
        }

        fclose(fp);
    }
    cputs("\n\nBACK TO BASIC\n");
    return 0;
}

