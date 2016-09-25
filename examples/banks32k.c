
#pragma options -machine=cocous

#include <stdio.h>
#include <string.h>
#include <bank.h>
#include <far.h>

int main(void)
{
    char* s1 = 0x8000;
    char* s2 = 0x8100;

    // Note: Bank 16 is the 32k under ROM.
    // All banks are 32k mapped to memory $8000

    bank_t bank = bank_set(16);
    strcpy(s1, "THE CMOC STANDARD 32K");
    bank_set(bank);

    bank = bank_set(16);
    strcpy(s2, "MEMORY BANK MODEL");
    bank_set(bank);

    bank = bank_set(16);
    puts(s1);
    bank_set(bank);

    bank = bank_set(16);
    puts(s2);
    bank_set(bank);

    puts("BACK TO BASIC");

    return 0;
}

