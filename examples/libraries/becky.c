
// Becky is the start of a very basic protocol for making HTTP requests.
// The Becky server is currently being written. Again, its very basic. Becky uses
// the becker port and provides byte-to-byte handshaking.

#include <conio.h>
#include <becky.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <equates.h>
#include <point.h>
#include <long.h>

#pragma options -machine=cocous -cart=becker

// TODO: Simple HTML reader

void test_html(void)
{
    if (becky_send_str(BECKY_HTTP, "GET http://cs.unc.edu/~yakowenk/coco/text/extendedbasic.html")) {
        if (becky_result.hi) {
            if (becky_result.lo == -1 && becky_result.hi == -1) {
                becky_send_null(BECKY_ERROR);
                char err[100];
                becky_recv_str(BECKY_READ, err, 80);
                cputs(err);
            } else {
                cputs("RESPONSE IS OVER 64K\n");
            }
        } else {
            char s[100];
            while (becky_result.lo && becky_recv_str(BECKY_READ, s, 32)) {
                cputs(s);
            }
        }
    }
}

void showimage(char* url)
{
    char buf[100];
    stpcpy(stpcpy(buf, "GET "), url);
    if (becky_send_str(BECKY_HTTP, buf) && becky_send_null(BECKY_IMAGE_LOAD)) {
        point_t p;
        p.x = 256;
        p.y = 192;
        if (becky_send_data(BECKY_IMAGE_RESAMPLE, (byte*)&p, sizeof(point_t))
            && becky_send_null(BECKY_IMAGE_SAVE_RAW)) {
            becky_recv_data(BECKY_READ, (byte*)_beggrp, _endgrp - _beggrp);
        }
    }
}

void test_image(void)
{
    system("PMODE4,1:SCREEN1,1:PCLS0");
    for (;;) {
        showimage("http://www.trs-80.org/images/coco1a.jpg");
        showimage("http://colorcomputer.50webs.com/logo.jpg");
        showimage("http://www.thecoolist.com/wp-content/uploads/2009/08/art-of-the-arcade_1.jpg");
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

    if (!becky_send_null(BECKY_MAGIC) || becky_result.lo != 1234) {
        exit("BECKY NOT AVALIABLE");
    }
    becky_send_null(BECKY_TITLE);
    char title[100];
    becky_recv_str(BECKY_READ, title, 32);
    cputs(title);
    cputs("\nPRESS ANY KEY\n");
    getch();
    test_html();

    //test_image();

    //test_html();
    return 0;
}

