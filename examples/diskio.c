
#include <equates.h>
#include <basic.h>
#include <fcntl.h>
#include <unistd.h>
#include <cmoc.h>

extern int _filedesc[FOPEN_MAX];

int main(void)
{
    char s[100];

    puts("Write out text file:");

    OPEN_O(1, "FILE.DAT");
    PRINT(1, "Derek\r");
    PRINT(1, "Was\r");
    PRINT(1, "Here\r");
    CLOSE(1);
    /*
    int fd = open("FILE.DAT", O_WRONLY);
    if (fd) {
        puts("WRITING");
        write(fd, "DEREK EVANS\nWAS HERE!", 23);
        close(fd);
    }
    */

    int fd = open("FILE.DAT", O_RDONLY);
    printf("SIZE:%d\n", lsize(fd));
    if (fd) {
        while (lgets(fd, s, 50)) {
            printf(">%s", s);
        }
        close(fd);
    }
    puts("");

    if (OPEN_I(1, "FILE.DAT")) {
        INPUT(1, s);
        printf(">%s", s);
        INPUT(1, s);
        printf(">%s", s);
        INPUT(1, s);
        printf(">%s", s);
    }

    return 0;
}

