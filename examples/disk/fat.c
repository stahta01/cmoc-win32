
#include <stdio.h>
#include <stdlib.h>
#include <fat.h>

int main(void)
{
    system("CLS");
    puts("LOADING FAT ...");
    fat_load(0);
    puts("DISPLAY FAT DATA");
    fat_t* fat = fat_get(0);
    for (int i = 0; i < sizeof(fat->dat); i++) {
        printf(" %02X ", fat->dat[i]);
    }
    puts("\n\nBACK TO BASIC");
    return 0;
}

