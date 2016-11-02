
#include "_eddie.h"

int eddie_line_at(char* str, size_t size, size_t at, size_t x, char* eolchars, bool leaveatend)
{
    char* pos = str + (x = min(x, strlen(str)));
    int chr, w, h, xy = at + x;
    gotoat(xy);
    screensize(&w, &h);
    for (int wh = w * h; !strchr(eolchars, chr = getch());) {
        switch (chr) {
        case ASCII_NAK:                             // SHIFT+LEFT
            if (pos > str) {
                pos--;
                gotoat(--xy);
            }
            break;
        case ASCII_HT:
            if (*pos) {
                pos++;
                gotoat(++xy);
            }
            break;
        case ASCII_BS:
            if (pos > str) {
                pos--;
                memcpy(pos, pos + 1, strlen(pos) + 1);
                gotoat(--xy);
                cputs(pos);
                cputc(' ');
                gotoat(xy);
            }
            break;
        default:
            if (isprint(chr) && strlen(str) < (size - 1)) {
                int poslen = strlen(pos) + 1;
                memcpy_r(pos + 1, pos, poslen);
                *pos = (char)chr;
                if (xy + poslen >= wh) {
                    xy -= w;
                    at -= w;
                }
                cputs(pos++);
                gotoat(++xy);
            }
            break;
        }
    }
    if (leaveatend) {
        gotoat(at + strlen(str));
    }
    return chr;
}

