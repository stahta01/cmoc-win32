
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <conio.h>
#include <heap.h>

//#pragma options -machine=coco

char* AllocMem(size_t size)
{
    char* memory = (char*) malloc(size);

    if (!memory) {
        cprintfxy(0, 2, "alloc error %d\n", size);
        exit(-1);
    }
    for (char i = 0; i < _msize(memory); i++) {
        memory[i] = i;
    }
    cprintfxy(0, 0, "%p: SIZE:%3d REQUESTED:%3d", memory, _msize(memory), size);
    return memory;
}

void FreeMem(char* memory)
{
    cprintfxy(0, 1, "%p: SIZE:%3d", memory, _msize(memory));
    for (char i = 0; i < _msize(memory); i++) {
        if (memory[i] != i) {
            cprintfxy(0, 2, "\ndata error P=%d SIZE=%u\n", i, _msize(memory));
            exit(-1);
        }
    }
    free(memory);
}

char* memory[32];

void Test()
{
    int i, j;
    gotoxy(0, 0);
    for (j = 0; j < 4; j++) {
        i = rand() & 31;
        if (!memory[i]) {
            memory[i] = AllocMem((rand() & 127) + 4);
        }
    }
    for (j = 0; j < 2; j++) {
        i = rand() & 31;
        if (memory[i]) {
            FreeMem(memory[i]);
            memory[i] = nullptr;
        }
    }
}

int main()
{
    clrscr();
    while (!kbhit()) {
        Test();
    }
    puts("MEMORY TEST COMPLETE");
    puts("BACK TO BASIC");

    return 0;
}

