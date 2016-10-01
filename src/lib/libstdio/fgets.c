
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
        // Since char is signed, the max for cgets is most
        // likely 126-ish. 100 will do.
        str[0] = size < 100 ? (char)size : 100;
        strcpy(str, cgets(str));
        cputc('\n');
        return str;
    }
}

