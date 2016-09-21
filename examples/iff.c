
// This is a _simple_ example of loading an IFF file. The image was created
// using Paintshop PRO. The code expects a 256x192, single plane (2 color)
// compressed image. I dont check for any errors.

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <equates.h>
#include <iff.h>
#include <rle.h>

int main(void)
{
    byte buf[4000];                             // Must be big enough for BODY data
    clrscr();
    puts("LOADING IFF IMAGE ...");
    FILE* fp = fopen("WINCMOC.IFF:1", "r");
    if (fp) {
        iff_head_t head;
        if (iff_head_read(&head, fp) && iff_head_is(&head, "FORM")) {
            fread(buf, 4, 1, fp);
            while (iff_head_read(&head, fp)) {
                fread(buf, 1, head.size.lo, fp);
                if (iff_head_is(&head, "BODY")) {
                    if (head.size.lo > sizeof(buf)) {
                        puts("IMAGE DATA TOO BIG");
                        exit(-1);
                    }
                    system("PMODE4,1");
                    system("SCREEN1,1");
                    rle_decode((byte*)_beggrp, buf, head.size.lo);
                    break;
                }
            }
        }
        fclose(fp);
    }
    getch();
    system("SCREEN0");
    puts("BACK TO BASIC");
    return 0;
}

