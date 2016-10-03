
#include <conio.h>
#include <unistd.h>
#include <fcntl.h>
#include <charset.h>

void PrintFileToConsole(char* fn)
{
    char s[100];
    cprintf("Searching for '%s'\n", fn);
    int fd = open(fn, O_RDONLY);
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
    // Fixed. BASIC.TXT was moved to drive #1.
    // Note: The prefered file commands are in stdio, which use DOS commands.
    // Soon the UNIX commands will also use the DOS commands. LibDisk
    // is still handy, but needs a clean up.
    _setDefaultDriveNo(1);

    bgcolor(3);
    textmode2(MODE_H0_64X24, charset_atari_small);
    PrintFileToConsole("BASIC.TXT");
    cputs("\n\nPress any key to exit");
    getch();
    textmode(0);
    cputs("BACK TO BASIC");
    return 0;
}

