
#include "_sscanf.h"

int vsscanf(char* str, char* fmt, va_list args)
{
    int count = 0;
    while (*str && *fmt) {
        switch (*fmt++) {
        default:
            if (*str == fmt[-1]) {
                str++;
            }
            break;
        case ' ':
            str = eat_while_space(str);
            break;
        case '%':
            char* tok, chr;
            switch (*fmt++) {
            default:
                fmt--;
                break;
            case 'c':
                *(char*)*args++ = *str++;
                break;
            case 's':
                chr = *(str = eat_until_space(tok = eat_while_space(str)));
                *str = 0;
                strcpy((char*)*args++, tok);
                *str = chr;
                break;
            case 'd':
            case 'i':
                chr = *(str = eat_integer(tok = eat_while_space(str)));
                *str = 0;
                *(int*)*args++ = atoi(tok);
                *str = chr;
                break;
            case 'u':
                chr = *(str = eat_while_digit(tok = eat_while_space(str)));
                *str = 0;
                *(unsigned*)*args++ = atoi(tok);
                *str = chr;
                break;
            }
            count++;
            break;
        }
    }
    return count;
}

