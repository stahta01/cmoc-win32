
#include <equates.h>
#include <basic.h>
#include <fcntl.h>
#include <unistd.h>
#include <cmoc.h>


int main(void)
{
    char s[100];

    puts("Write out text file:");
    OPEN_O(1, "FILE");
    PRINT(1, "Welcome\n to the\n");
    PRINT(1, "TO THE COCO\n");
    CLOSE(1);

    //int fd = open("FILE", O_WRONLY);
    //if (fd) {
    //    write(fd, "DEREK EVANS", 11);
    //    close(fd);
    //}

    if (OPEN_I(1, "FILE")) {
        INPUT(1, s);
        puts(s);
        INPUT(1, s);
        puts(s);
        INPUT(1, s);
        puts(s);
    }

    return 0;
}

