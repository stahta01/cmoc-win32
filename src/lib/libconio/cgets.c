
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include <equates.h>

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
    s[0] = 0;
    char* p = s;
    for (;;) {
        char c = getch();
        if (c == _CR) {
            break;
        }
        switch (c) {
        case 94:
            if (p > s) {
                p--;
                putlt();
            }
            break;
        case 9:
            if (*p) {
                p++;
                putrt();
            }
            break;
        case _BS:
            if (p > s) {
                p--;
                memmove(p, p + 1, strlen(p) + 1);
                putlt();
                cputs(p);
                putch(' ');
                for (int i = strlen(p) + 1; i-- > 0;) {
                    putlt();
                }
            }
            break;
        default:
            if (strlen(s) < ((unsigned)s[-2]) && _isprint(c)) {
                memmove(p + 1, p, strlen(p) + 1);
                *p = c;
                cputs(p);
                for (int i = strlen(p) - 1; i-- > 0;) {
                    putlt();
                }
                p++;
            }
            break;
        }
    }
    s[-1] = (char)strlen(s);
    return s;
}
