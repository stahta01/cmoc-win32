
#pragma options -machine=cocous

#include <stdio.h>
#include <string.h>
#include <bank.h>

int main(void)
{
    char* s1 = 0x8000;
    char* s2 = 0x8100;

    // Note: Bank 0 is the 32k under ROM.
    // All banks are 32k mapped to memory $8000

    bank_t bank = bank_set(0);
    strcpy(s1, "THE CMOC STANDARD 32K");
    bank_set(bank);

    bank = bank_set(0);
    strcpy(s2, "MEMORY BANK MODEL");
    bank_set(bank);

    bank = bank_set(0);
    puts(s1);
    bank_set(bank);

    bank = bank_set(0);
    puts(s2);
    bank_set(bank);

    puts("BACK TO BASIC");

    return 0;
}

