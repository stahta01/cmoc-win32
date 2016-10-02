
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

int main(void)
{
    errno = 0;
    system("OPEN\"I\",1,\"nofile\"");
    printf("ERRNO=%d\n", errno);
    puts("RETURN TO BASIC");
    return 0;
}

