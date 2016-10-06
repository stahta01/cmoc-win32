
#include "_conio.h"

/*
cgets reads a string of characters from the console, storing the string (and the string length)
in the location pointed to by str. cgets reads characters until it encounters a carriage-return/linefeed
(CR/LF) combination, or until the maximum allowable number of characters have been read.
If cgets reads a CR/LF combination, it replaces the combination with a \0 (null terminator)
before storing the string. Before cgets is called, set str[0] to the maximum length of the string
to be read. On return, str[1] is set to the number of characters actually read. The characters
read start at str[2] and end with a null terminator. Thus, str must be at least str[0] plus 2 bytes long.
*/

char* cgets(char* str)
{
    int w, h;
    screensize(&w, &h);
    int screenendat = w * h;
    int curpos = whereat();
    str += 2;
    str[0] = 0;
    char* pos = str;
    for (int chr; (chr = getch()) != ASCII_CR;) {
        int at = whereat();
        switch (chr) {
        case ASCII_NAK:                         // SHIFT+LEFT
            if (pos > str) {
                pos--;
                gotoat(at - 1);
            }
            break;
        case ASCII_HT:
            if (*pos) {
                pos++;
                gotoat(at + 1);
            }
            break;
        case ASCII_BS:
            if (pos > str) {
                pos--;
                memcpy(pos, pos + 1, strlen(pos) + 1);
                gotoat(--at);
                _putstr(pos);
                putch(' ');
                gotoat(at);
            }
            break;
        default:
            if (isprint(chr) && strlen(str) < (((word)str[-2]) - 1)) {
                int poslen = strlen(pos) + 1;
                _memcpy_rev(pos + 1, pos, poslen);
                *pos = (char)chr;
                if (at + poslen >= screenendat) {
                    at -= w;
                    curpos -= w;
                }
                _putstr(pos++);
                gotoat(at);
                cursormove(VT52_CHR_RIGHT);
            }
            break;
        }
    }
    str[-1] = (char)strlen(str);
    gotoat(curpos + str[-1]);
    return str;
}

