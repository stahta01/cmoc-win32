
#include <equates.h>
#include <basic.h>
#include <fcntl.h>
#include <unistd.h>
#include <cmoc.h>

extern int _filedesc[FOPEN_MAX];

void INPUT2(int f, char* s)
{
    if (f) {
        struct FileDesc* filedesc = (struct FileDesc*)_filedesc[f];
        if (filedesc > FOPEN_MAX) {
            char buf[100];
            word offset[2];

            offset[0] = filedesc->offset[0];
            offset[1] = filedesc->offset[1];

            char* pos = buf;
            for (;;) {
                word len = read(filedesc, pos, 16);
                pos[len] = 0;
                char* eol = strchr(pos, '\n');
                if (eol) {
                    *eol = 0;
                    break;
                }
                if (len < 16) {
                    break;
                }
                pos += len;
            }
            adddww(offset, strlen(buf) + 1);
            _seek(filedesc, offset);
            strcpy(s, buf);
        }
    } else {
        cgets(s);
    }
}

int main(void)
{
    char s[100];

    puts("Write out text file:");

    OPEN_O(1, "TEST.DAT");
    PRINT(1, "Derek\n");
    PRINT(1, "Was\n");
    PRINT(1, "Here\n");
    CLOSE(1);
    /*
    int fd = open("FILE.DAT", O_WRONLY);
    if (fd) {
        puts("WRITING");
        write(fd, "DEREK EVANS\nasdfasdf\n", 23);
        close(fd);
    }
    */

    int fd = open("FILE.DAT", O_RDONLY);
    if (fd) {
        while (lgets(fd, s, 50)) {
            puts(s);
        }
        close(fd);
    }

    /*
    if (OPEN_I(1, "FILE.DAT")) {
        INPUT2(1, s);
        printf(">%s", s);
        INPUT2(1, s);
        printf(">%s", s);
        INPUT2(1, s);
        printf(">%s", s);
    }
    */
    return 0;
}

