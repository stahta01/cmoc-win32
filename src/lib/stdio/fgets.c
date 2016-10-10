
#include "_stdio.h"

char* fgets(char* str, size_t size, FILE* fp)
{
    if (fp->dev) {
        char* result = str;
        int chr = EOF;
        // The null term is included in size, therefore a size of <= 1
        // does not read anything.
        while (size-- > 1) {
            chr = fgetc(fp);
            if (chr == EOF) {
                break;
            }
            *str++ = (char)chr;
            if (chr == '\n' || chr == '\r') {
                break;
            }
        }
        *str = 0;
        return chr == EOF ? (char*)nullptr : result;
    } else {
        char buf[MAX_INPUT];
        buf[0] = size < MAX_INPUT ? size : MAX_INPUT;
        strcpy(str, cgets(buf));
        cputc('\n');
        return str;
    }
}

