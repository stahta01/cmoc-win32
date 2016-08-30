
#include <basic.h>
#include <fcntl.h>
#include <unistd.h>

#define FILENAME "FILE.TXT"

void ExampleBasic(void)
{
    char s[100];

    puts("*BASIC STYLE");

    OPEN_O(1, FILENAME);
    PRINT(1, "WRITING A FILE\r");
    PRINT(1, "USING BASIC STYLE\r");
    PRINT(1, "COMMANDS\r");
    CLOSE(1);
    if (OPEN_I(1, FILENAME)) {
        while (INPUT(1, s)) {
            printf(">%s\n", s);
        }
    }
}

void ExampleUnix(void)
{
    char s[100];

    puts("*UNIX STYLE");

    int fd = open(FILENAME, O_WRONLY);
    if (fd) {
        strcpy(s, "WRITING A FILE\nUSING UNIX\nSTYLE COMMANDS\nCOOL!\n");
        write(fd, s, strlen(s));
        close(fd);
    }
    fd = open(FILENAME, O_RDONLY);
    printf("SIZE:%d\n", lsize(fd));
    if (fd) {
        while (lgets(fd, s, 50)) {
            if (s[0] != '\n') {
                printf(">%s", s);
            }
        }
        close(fd);
    }
}

int main(void)
{
    ExampleBasic();
    ExampleUnix();
    puts("DONE");
    return 0;
}

