
#include "_sscanf.h"

int vsscanf(char* str, char* fmt, va_list args)
{
    int count = 0;
    char chr;
    for (str = eat_while_space(str); *str && (chr = *fmt++);) {
        switch (chr) {
        default:
            if (*str == chr) {
                str++;
            }
            break;
        case ' ':
            str = eat_while_space(str);
            break;
        case '%':
            char* tok = str;
            switch (*fmt++) {
            case 0:
                goto done;
                break;
            case 'c':
                chr = *(char*)*args++ = *str;
                break;
            case 's':
                chr = *(str = eat_until(str, isspace));
                *str = 0;
                strcpy((char*)*args++, tok);
                break;
            case 'd':
            case 'i':
                chr = *(str = eat_integer(str));
                *str = 0;
                *(int*)*args++ = atoi(tok);
                break;
            case 'u':
                chr = *(str = eat_while(str, isdigit));
                *str = 0;
                *(unsigned*)*args++ = atoi(tok);
                break;
            default:
                goto done;
            }
            count++;
            if (*str = chr) {
                str++;
            }
            break;
        }
    }
done:
    return count;
}

