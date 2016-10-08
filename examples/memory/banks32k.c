
//#pragma options -machine=cocous

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <bank.h>

#include <machine.h>
#include <coco/coco3.h>
#include <coco/super.h>

int main(void)
{
    system("WIDTH40");

    char* s1 = 0x8000;
    char* s2 = 0x9000;

    // Note: Bank 0 is the 32k under ROM.
    // Bank 15 is the default RAM/ROM mode, but you should always
    // use the return value from bank_set().
    // All banks are 32k mapped to memory $8000

#define BANK 0

    char s[100];
    bank_t bank = bank_set(BANK);
    strcpy(s1, "THE CMOC STANDARD 32K");
    bank_set(bank);

    bank = bank_set(BANK);
    strcpy(s2, "MEMORY BANK MODEL");
    bank_set(bank);

    bank = bank_set(BANK);
    strcpy(s, s1);                              // We cant puts from a bank in 40/80 col mode (CoCo 3)
    bank_set(bank);
    puts(s);

    bank = bank_set(BANK);
    strcpy(s, s2);                              // We cant puts from a bank in 40/80 col mode (CoCo 3)
    bank_set(bank);
    puts(s);

    puts("\nBACK TO BASIC");

    return 0;
}

