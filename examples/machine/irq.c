
// A simple irq example.
// When the irq's are disabled, you are able todo things like access the RAM
// under ROM. irq_set() alows you to restore the previous irq settings,
// which is handy for code that needs to work in both RAM & ROM modes.

#include <stdio.h>
#include <irq.h>

int main(void)
{
    char s[100];
    word irq = irq_set(IRQ_DISABLE_SLOW);
    puts("THE CURSOR WONT BLINK BECAUSE");
    puts("THE TIMER IS DISABLED");
    gets(s);
    irq_set(irq);                               // Aways restore the previous IRQ settings.
    puts("NOW THE CURSOR WILL BLINK");
    gets(s);
    puts("BACK TO BASIC");
    return 0;
}

