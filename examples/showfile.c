
#include <conio.h>
#include <stdio.h>
#include <charset.h>

// Text mode bin = 6,211 bytes
// Graph mode bin = 10,657 bytes + (6144 of graphics) = ~10K

// While conio graphics are cool, if you want more space for data, you
// need to use text mode only. Or, use libfar to store your data.

//#define _USE_TEXT_MODE

void PrintFileToConsole(char* fn)
{
    char s[100];
    cwritef("Searching for '%s'\n", fn);
    FILE* fp = fopen(fn, "r");
    if (fp) {
        while (!feof(fp)) {
            char s[33];
            fgets(s, sizeof(s), fp);
            if (s[0] != '\r') {
                fputs(s, stdout);
            }
        }
        fclose(fp);
    }
}

int main(void)
{
#ifndef _USE_TEXT_MODE
    // conio now uses late binding for graphics text. This prevents
    // libgraph from being linked into your bin for video ram only
    // programs. Therefore, you must now call conio_uses_graph()
    // if you want to display text on a graphics screen.
    conio_uses_graph();
    bgcolor(0);
    textmode2(MODE_H0_64X24, charset_atari_small);
#endif
    PrintFileToConsole("B:BASIC.TXT");
    cputs("\n\nPress any key to exit");
    getch();
#ifndef _USE_TEXT_MODE
    textmode(0);
#endif
    cputs("BACK TO BASIC");
    return 0;
}

