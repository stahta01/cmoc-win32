
#pragma options -machine=cocous

#include <conio.h>
#include <unistd.h>
#include <fcntl.h>

void PrintFileToConsole(char* fn)
{
    char s[100];
    cprintf("Searching for '%s'\n", fn);
    int fd = open("BASIC.TXT", O_RDONLY);
    if (fd) {
        while (lgets(fd, s, sizeof(s))) {
            if (s[0] != '\n') {
                cprintf("%s", s);
            }
            if (kbhit()) {
                getch();
                break;
            }
        }
        close(fd);
    } else {
        cputs("Unable to load file");
    }
}

int main(void)
{
    bgcolor(1);
    textmode(MODE_H0_64X24);
    PrintFileToConsole("BASIC.TXT");
    cputs("\n\nPress any key to exit");
    getch();
    textmode(0);
    cputs("BACK TO BASIC");
    return 0;
}

