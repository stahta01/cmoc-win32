
//#pragma options -machine=cocous

// This is a _simple_ example of loading an IFF file. The image was created
// using Paintshop PRO. The code expects a 256x192, single plane (2 color)
// compressed image. I dont check for any errors.

// UPDATE
// I wrote a quick RLE compressor. This example now displays the compressed data, then
// re-compresses the image, and then re-displays.
// The size of the new compressed data, and the size of the original are shown.
// For some reason, my compressor produces smaller sizes. Im unsure why... But, its better
// than bigger sizes.

// NOTE: Demo now uses alloca to allocate memory on the stack for the body. No check is
// made to see if the body is too big.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <equates.h>
#include <iff.h>
#include <rle.h>
#include <alloca.h>

int main(void)
{
    byte littlechunk[100];                          // Should be big enough for non-body chunks.
    clrscr();
    puts("LOADING IFF IMAGE ...");
    FILE* fp = fopen("WINCMOC.IFF:1", "r");
    if (fp) {
        iff_head_t head;
        if (iff_head_read(&head, fp) && iff_head_is(&head, "FORM")) {
            fread(littlechunk, 4, 1, fp);
            while (iff_head_read(&head, fp)) {
                if (iff_head_is(&head, "BODY")) {
                    byte* body = (byte*)alloca(head.size.lo);
                    fread(body, 1, head.size.lo, fp);
                    system("PMODE4,1");
                    system("SCREEN1,1");
                    rle_decode((byte*)_beggrp, body, _endgrp - _beggrp);
                    byte* end = rle_encode(body, (byte*)_beggrp, _endgrp - _beggrp);
                    system("PCLS");
                    system("SCREEN,0");
                    rle_decode((byte*)_beggrp, body, _endgrp - _beggrp);
                    printf("SIZES: NEW=%d OLD=%ld\n", end - body, &head.size);
                    break;
                } else {
                    // This should be a fseek, but, we dont have it yet
                    fread(littlechunk, 1, head.size.lo, fp);
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

