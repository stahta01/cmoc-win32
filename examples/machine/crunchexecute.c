
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <system.h>

char* sound1 = strdup(system_crunch("PLAY\"L64CFGAB\""));
char* sound2 = strdup(system_crunch("PLAY\"L64FCEFA\""));
char* sound3 = strdup(system_crunch("PLAY\"L64BAFGA\""));
char* string = strdup(system_crunch(
                          "PRINT@228,\"THE CMOC COMPILER ROCKS!!\";:"
                          "PRINT@262,\"PRESS ANY KEY TO EXIT\";"));
char* clear1 = strdup(system_crunch("CLS2"));
char* clear2 = strdup(system_crunch("CLS3"));
char* clear3 = strdup(system_crunch("CLS4"));

int main(void)
{
    system_execute(sound1);
    while (!kbhit()) {
        system_execute(clear1);
        system_execute(string);
        system_execute(sound2);
        system_execute(clear2);
        system_execute(string);
        system_execute(sound3);
        system_execute(clear3);
        system_execute(string);
        system_execute(sound2);
        system_execute(sound1);
    }
    system_execute(clear1);
    system_execute(sound2);
    puts("BACK TO BASIC");
    return 0;
}

