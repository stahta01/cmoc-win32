
#pragma options -machine=cocous

// This is a _simple_ example of loading an IFF file. The image was created
// using Paintshop PRO. The code expects a 256x192, single plane (2 color)
// compressed image. I dont check for any errors.

// UPDATE
// I wrote a quick RLE compressor. This example now displays the compressed data, then
// re-compresses the image, and then re-displays.
// The size of the new compressed data, and the size of the original are shown.
// For some reason, my compressor produces smaller sizes. Im unsure why... But, its better
// than bigger sizes.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <equates.h>
#include <iff.h>
#include <rle.h>

int main(void)
{
    byte buf[4000];                             // Must be big enough for BODY data
    clrscr();
    puts("LOADING IFF IMAGE ...");
    // stdio now uses DOS style devices. A-D=disk,T=tape,P=Printer,S=Screen.
    FILE* fp = fopen("B:WINCMOC.IFF", "r");
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
                    rle_decode((byte*)_beggrp, buf, _endgrp - _beggrp);
                    byte* end = rle_encode(buf, (byte*)_beggrp, _endgrp - _beggrp);
                    system("PCLS");
                    system("SCREEN,0");
                    rle_decode((byte*)_beggrp, buf, _endgrp - _beggrp);
                    printf("SIZES: NEW=%d OLD=%ld\n", end - buf, &head.size);
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

