
#include <stdio.h>
#include <equates.h>
#include <stdlib.h>

#include <conio.h>

int main(void)
{
    char s[100];
    FILE* fp;

    cputs("INSERT TAPE & PRESS RECORD.\nPRESS ANY KEY WHEN READY.\n");
    getch();
    cputs("WRITING FILE ...");
    fp = fopenf("TEST.TXT:%d", "w", -1);
    if (fp) {
        for (int i = 0; i < 20; i++) {
            fprintf(fp, "TAPE STRING #%d\r", i);
        }
        fclose(fp);
    }
    cputs("\nREWIND & PLAY TAPE.\nPRESS ANY KEY WHEN READY.\n");
    getch();
    fp = fopenf("TEST.TXT:%d", "r", -1);
    if (fp) {
        int chr;
        while ((chr = fgetc(fp)) != EOF) {
            cprintf("%c", chr);
        }
        cputs("DONE\n");
        fclose(fp);
    }
    cputs("BACK TO BASIC\n");
    return 0;
}

