
#include "_stdio.h"

char* fgets(char* s, size_t n, FILE* fp)
{
    if (fp->dev) {
        char* start = s;
        int c = EOF;
        while (n-- > 1) {
            c = fgetc(fp);
            if (c == EOF) {
                break;
            }
            *s++ = (char)c;
            if (c == '\n' || c == '\r') {
                break;
            }
        }
        *s = 0;
        return c == EOF ? (char*)NULL : start;
    } else {
        // Since char is signed, the max for cgets is most
        // likely 126-ish.
        s[0] = n < 100 ? (char)n : 100;
        strcpy(s, cgets(s));
        cputc('\n');
        return s;
    }
}

