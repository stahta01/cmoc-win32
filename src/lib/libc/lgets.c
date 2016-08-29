
#include <stdio.h>
#include <string.h>
#include <unistd.h>

size_t lgets(int fd, char* s, size_t n)
{
    int tell = ltell(fd);
    char buf[BUFSIZ], *end = buf;
    do {
        end[read(fd, end, 16)] = 0;
        while (*end && *end != '\n' && *end != '\r') {
            end++;
        }
    } while (!*end);
    end[1] = 0;
    strcpy(s, buf);
    lseek(fd, tell + end - buf + 1, SEEK_SET);
    return end - buf + 1;
}

