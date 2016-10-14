
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
            word hi, lo;
            becky_recvword(&hi);
            becky_recvword(&lo);
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
    if (becky_sendrequest(buf) && becky_sendword_wait(BECKY_NULL, 1000)) {
        if (becky_sendword(BECKY_IMAGE_LOAD) && becky_sendword(BECKY_IMAGE_RESAMPLE) && becky_sendword(192)
            && becky_sendword(256)) {
            if (becky_sendword_wait(BECKY_NULL, 1000)) {
                if (becky_sendword(BECKY_IMAGE_SAVE_RAW) && becky_sendword_wait(BECKY_RESPONSE, 1000)) {
                    word hi, lo;
                    becky_recvword(&hi);
                    becky_recvword(&lo);
                    byte* dst = (byte*)_beggrp;
                    while (lo-- && becky_recvbyte(dst)) {
                        dst++;
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
        showimage("http://www.vintage-computer.com/images/apple2running.jpg");
        showimage("http://www.old-computers.com/museum/photos/Tandy_Color3_System_s1.jpg");
        showimage("http://www.nerdlikeyou.com/wp-content/uploads/2013/03/retro-consoles-commodore-64-and-screen.jpg");
        showimage("http://meme-lol.com/wp-content/uploads/meme-lol/Funny-LOL-Ferret.jpg");
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

