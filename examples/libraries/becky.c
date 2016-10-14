
// Becky is the start of a very basic protocol for making HTTP requests.
// The Becky server is currently being written. Again, its very basic. Becky uses
// the becker port and provides byte-to-byte handshaking.

#include <conio.h>
#include <becky.h>
#include <unistd.h>

#pragma options -machine=coco2b -cart=becker

// TODO: Simple HTML reader

int main(void)
{
    *(byte*)0xff22 |= 16;                           // lower case letters

    cputs("WAIT FOR XROAR TO CONNECT\n");
    sleep(1);

    char title[100];
    if (becky_sendword(BECKY_TITLE) && becky_recvstring(title, sizeof(title))) {
        cwritef("%s\n", title);
    } else {
        becky_sendword(BECKY_FAILURE);
    }
    if (becky_sendrequest("GET http://cs.unc.edu/~yakowenk/coco/text/extendedbasic.html")) {
        if (becky_sendword_wait(BECKY_RESPONSE, 1000)) {
            byte b;
            while (becky_recvbyte(&b)) {
                cputc(b);
            }
        }
    } else {
        cputs("UNABLE TO CONNECT TO BECKY\n");
    }
    cputs("BACK TO BASIC\n");
    return 0;
}

