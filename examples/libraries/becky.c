
// Becky is the start of a very basic protocol for making HTTP requests.
// The Becky server is currently being written. Again, its very basic. Becky uses
// the becker port and provides byte-to-byte handshaking.

#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <becky.h>

#pragma options -machine=cocous -cart=becker

int main(void)
{
    if (becky_sendstring("GET http://cs.unc.edu/~yakowenk/coco/text/extendedbasic.html")) {
        if (becky_request(20, 1000)) {
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

