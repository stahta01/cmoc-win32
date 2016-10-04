
#include "_unistd.h"

size_t lgets(int fd, char* s, size_t n)
{
    size_t size, tell = ltell(fd);
    char buf[BUFSIZ], *end = buf;
    do {
        size = read(fd, end, 16);
        end[size] = 0;
        while (*end && *end != '\n' && *end != '\r') {
            end++;
        }
    } while (size && !*end);
    if (*end) {
        end++;
    }
    size = end - buf;
    memcpy(s, buf, size);
    s[size] = 0;
    lseek(fd, tell + size, SEEK_SET);
    return size;
}

