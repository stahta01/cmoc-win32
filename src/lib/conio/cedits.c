
#include "_conio.h"

void cedits(char* str, size_t size, char* eolchars, bool leaveatend)
{
    *str = 0;
    int w, h, curpos = whereat();
    screensize(&w, &h);
    int screenendat = w * h;
    char* pos = str;
    for (int chr; !strchr(eolchars, chr = getch());) {
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
            if (isprint(chr) && strlen(str) < (size - 1)) {
                int poslen = strlen(pos) + 1;
                _memrcpy(pos + 1, pos, poslen);
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
    if (leaveatend) {
        gotoat(curpos + strlen(str));
    }
}

