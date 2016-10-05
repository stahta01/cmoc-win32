
#include "_sscanf.h"

int vsscanf(char* src, char* fmt, va_list args)
{
    int count = 0;
    char chr;
    for (src = eat_while_space(src); *src && (chr = *fmt++);) {
        switch (chr) {
        default:
            if (*src == chr) {
                src++;
            }
            break;
        case ' ':
            src = eat_while_space(src);
            break;
        case '%':
            char* tok = src;
            switch (*fmt++) {
            case 0:
                goto done;
                break;
            case 'c':
                chr = *(char*)*args++ = *src;
                break;
            case 's':
                chr = *(src = eat_until(src, isspace));
                *src = 0;
                strcpy((char*)*args++, tok);
                break;
            case 'd':
            case 'i':
                chr = *(src = eat_integer(src));
                *src = 0;
                *(int*)*args++ = atoi(tok);
                break;
            case 'u':
                chr = *(src = eat_while(src, isdigit));
                *src = 0;
                *(unsigned*)*args++ = atoi(tok);
                break;
            default:
                goto done;
            }
            count++;
            if (*src = chr) {
                src++;
            }
            break;
        }
    }
done:
    return count;
}

