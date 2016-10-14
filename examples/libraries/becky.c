
// Becky is the start of a very basic protocol for making HTTP requests.
// The Becky server is currently being written. Again, its very basic. Becky uses
// the becker port and provides byte-to-byte handshaking.

#include <conio.h>
#include <becky.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <equates.h>

#pragma options -machine=cocous -cart=becker

// TODO: Simple HTML reader

void test_html(void)
{
    if (becky_sendrequest("GET http://cs.unc.edu/~yakowenk/coco/text/extendedbasic.html")) {
        if (becky_sendword_wait(BECKY_RESPONSE, 1000)) {
            byte b;
            while (becky_recvbyte(&b)) {
                cputc(b);
            }
        }
    }
}

void showimage(char* url)
{
    char buf[100];
    stpcpy(stpcpy(buf, "GET "), url);
    if (becky_sendrequest(buf)) {
        if (becky_sendword_wait(BECKY_NULL, 1000)) {
            if (becky_sendword(BECKY_IMAGE_LOAD) && becky_sendword(BECKY_IMAGE_RESAMPLE) && becky_sendword(192)
                && becky_sendword(256)) {
                if (becky_sendword_wait(BECKY_NULL, 1000)) {
                    if (becky_sendword(BECKY_IMAGE_SAVE_RAW) && becky_sendword_wait(BECKY_RESPONSE, 1000)) {
                        byte* dst = (byte*)_beggrp;
                        while (becky_recvbyte(dst)) {
                            dst++;
                        }
                    }
                }
            }
        }
    }
}

void test_image(void)
{
    system("PMODE4,1:SCREEN1,1:PCLS0");
    for (;;) {
        showimage("http://meme-lol.com/wp-content/uploads/meme-lol/Funny-LOL-Ferret.jpg");
        showimage("http://harry.enzoverder.be/cats/funny-pictures-static-kitten.jpg");
        showimage("http://funny-pics.co/wp-content/uploads/Funny-silly-dog.jpg");
    }
}

int main(void)
{
    cputs("WAIT FOR XROAR TO CONNECT\n");
    sleep(1);

    char title[100];

    if (becky_sendword(BECKY_TITLE) && becky_recvstring(title, sizeof(title))) {
        cwritef("%s\n", title);
        test_image();
    } else {
        cputs("UNABLE TO CONNECT TO BECKY\n");
    }
    cputs("BACK TO BASIC\n");
    return 0;
}

