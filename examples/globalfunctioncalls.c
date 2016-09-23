
// I didn't realize CMOC allowed global function calls! O, my.
// Anyway, I had to adjust my startup code to make sure the system was setup before
// calling INITGL.

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void* mem = malloc(200);

int g[] = {
    puts("WOW! CMOC ALLOC FUNCTION CALLS"),
    puts("IN GLOBAL ARRAYS. I AM KINDA"),
    puts("SHOCKED ATM. I HAD TO ADJUST"),
    puts("WINCMOC TO ALLOW THIS TO WORK\n")
};

int main(void)
{
    printf("MEMORY SIZE: %u\n", _msize(mem));
    puts("I GUESS, REMEMBER, EACH LIB/OBJ");
    puts("HAS ITS OWN INIT CALL, AND THE");
    puts("CALL ORDER IS UNDEFINED.\n");
    puts("BACK TO BASIC");

    return 0;
}

