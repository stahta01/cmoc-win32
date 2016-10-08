
#include "_eddie.h"

int eddie_line(char* str, size_t size, char* eolchars, bool leaveatend)
{
    *str = 0;
    int chr, w, h, curpos = whereat();
    screensize(&w, &h);
    int dispen = w * h;
    char* pos = str;
    while (!strchr(eolchars, chr = getch())) {
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
                cputs(pos);
                cputc(' ');
                gotoat(at);
            }
            break;
        default:
            if (isprint(chr) && strlen(str) < (size - 1)) {
                int poslen = strlen(pos) + 1;
                memcpy_r(pos + 1, pos, poslen);
                *pos = (char)chr;
                if (at + poslen >= dispen) {
                    at -= w;
                    curpos -= w;
                }
                cputs(pos++);
                gotoat(at);
                cursormove(VT52_CHR_RIGHT);
            }
            break;
        }
    }
    if (leaveatend) {
        gotoat(curpos + strlen(str));
    }
    return chr;
}

