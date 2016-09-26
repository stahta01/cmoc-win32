
// An example of 16 heaps. 1 per videoram line.
// Memory is allocated with random sizes, and filled with known data.
// Memory is freed at random, and checked for the required data.

// libheap has been though a lot of testing in the last few days. I hope
// I have all the bugs out, because it is the basis for all memory allocations,
// including the hank/far library routines which handle heaps across multiple
// 32k memory banks. libfar handles everything from far data access, to
// bank to bank copies. It should also handle reallocation were the data
// outgrows its current bank, and is shifted to another.

#include <conio.h>
#include <stdlib.h>
#include <heap.h>

heap_t* heaps[16];
char* mem[16][4];

int main(void)
{
    int i, j, k;

    clrscr();
    cursor(false);                              // The cursor corrupts our heaps.

    for (i = 0; i < 16; i++) {
        heaps[i] = (int*)(1024 + i * 32);
        heap_init(heaps[i], 32);
    }

    while (!kbhit()) {
        for (i = 0; i < 16; i++) {
            j = rand() & 3;
            if (mem[i][j]) {
                for (k = 0; k < heap_msize(mem[i][j]); k++) {
                    if (mem[i][j][k] != 'A' + k) {
                        cputs("DATA ERROR!\n");
                        exit(-1);
                    }
                }
                heap_free((void*)mem[i][j]);
            }
            int* heap = (int*)(1024 + i * 32);
            mem[i][j] = (char*)heap_malloc(heap, (rand() & 5) + 1);
            if (mem[i][j]) {
                for (k = 0; k < heap_msize(mem[i][j]); k++) {
                    mem[i][j][k] = (char)('A' + k);
                }
            }
        }
    }
    cputs("BACK TO BASIC\n");
    return 0;
}

