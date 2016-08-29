
#pragma target coco

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include <conio.h>

char* AllocMem(uint8_t size)
{
    char* m = (char*) malloc(size);
    uint8_t i;

    if (!m) {
        puts("alloc error");
    }
    for (i = 0; i < _msize(m); i++) {
        m[i] = i;
    }
    printf("SIZE:%d MSIZE:%d\n", size, _msize(m));
    return m;
}

void FreeMem(char* m)
{
    int i;
    for (i = 0; i < _msize(m); i++) {
        if (m[i] != i) {
            puts("data error");
        }
    }
    free(m);
}

void Test()
{
    uint8_t i;
    char*   m[5];
    for (i = 0; i < 5; i++) {
        m[i] = AllocMem((uint8_t)((rand() % 100) + 1));
    }
    for (i = 0; i < 5; i++) {
        FreeMem(m[i]);
    }
}

int main()
{
    while (!kbhit()) {
        Test();
    }

    puts("MEMORY TEST COMPLETE");

    return 0;
}

