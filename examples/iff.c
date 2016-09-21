
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <iff.h>
#include <rle.h>
#include <equates.h>

int main(void)
{
    system("DRIVE1");
    FILE* fp = fopen("IMAGE.IFF", "r");
    if (fp) {
        iff_head_t head;
        if (iff_head_read(&head, fp) && iff_head_is(&head, "FORM")) {
            byte buf[4000];
            fread(buf, 4, 1, fp);
            while (iff_head_read(&head, fp)) {
                fread(buf, 1, head.size.lo, fp);
                if (iff_head_is(&head, "BODY")) {
                    if (head.size.lo > sizeof(buf)) {
                        exit(-1);
                    }
                    system("PMODE4,1");
                    system("SCREEN1,1");
                    rle_decode((byte*)_beggrp, buf, head.size.lo);
                }
            }
        }
        fclose(fp);
    }
    return 0;
}

