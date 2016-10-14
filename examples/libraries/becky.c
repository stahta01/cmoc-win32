
// Becky is the start of a very basic protocol for making HTTP requests.
// The Becky server is currently being written. Again, its very basic. Becky uses
// the becker port and provides byte-to-byte handshaking.

#include <conio.h>
#include <becky.h>

#pragma options -machine=coco2b -cart=becker

// TODO: Simple HTML reader
// BUG: Sometimes Becky fails. The Becker server stream might need to be flushed
// on errors.

int main(void)
{
    *(byte*)0xff22 |= 16;                           // lower case letters

    if (becky_sendstring("GET http://cs.unc.edu/~yakowenk/coco/text/extendedbasic.html")) {
        if (becky_sendword_wait(BECKY_BUFFER, 1000)) {
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

