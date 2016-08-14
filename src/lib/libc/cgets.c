
#include <conio.h>
#include <ctype.h>

/*
cgets reads a string of characters from the console, storing the string (and the string length)
in the location pointed to by str. cgets reads characters until it encounters a carriage-return/linefeed
(CR/LF) combination, or until the maximum allowable number of characters have been read.
If cgets reads a CR/LF combination, it replaces the combination with a \0 (null terminator)
before storing the string. Before cgets is called, set str[0] to the maximum length of the string
to be read. On return, str[1] is set to the number of characters actually read. The characters
read start at str[2] and end with a null terminator. Thus, str must be at least str[0] plus 2 bytes long.
*/

char* cgets(char* s)
{
    s += 2;
    char* e = s;
    for (;;) {
        cputc(128 + 5);
        while (!kbhit()) {}
        char c = getch();
        cputc(8);
        if (c == 13) {
            break;
        } else if (c == 8) {
            if (e > s) {
                e--;
                cputc(8);
            }
        } else {
            if ((e - s) < ((unsigned)s[-2]) && isprint(c)) {
                *e++ = c;
                cputc(c);
            }
        }
    }
    *e = 0;
    s[-1] = (char)(e - s);
    return s;
}



