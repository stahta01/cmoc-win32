
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
        char cc = *(unsigned char*)_curpos;
        while (!kbhit()) {
            *(unsigned char*)_curpos = *(unsigned*)_TIMVAL & 16 ? cc | 64 : cc;
        }
        *(unsigned char*)_curpos = cc;
        char c = getch();
        if (c == _CR) {
            break;
        }
        switch (c) {
        case 94:
            if (p > s) {
                p--;
                cputlt();
            }
            break;
        case 9:
            if (*p) {
                p++;
                cputrt();
            }
            break;
        case _BS:
            if (p > s) {
                p--;
                memmove(p, p + 1, strlen(p) + 1);
                cputlt();
                unsigned cp = _curpos;
                cputs(p);
                cputc(_SPACE);
                _curpos = cp;
            }
            break;
        default:
            if (strlen(s) < ((unsigned)s[-2]) && _isprint(c)) {
                memmove(p + 1, p, strlen(p) + 1);
                *p = c;
                unsigned cp = _curpos;
                cputs(p);
                _curpos = cp;
                cputrt();
                p++;
            }
            break;
        }
    }
    *p = 0;
    s[-1] = (char)strlen(s);
    return s;
}

