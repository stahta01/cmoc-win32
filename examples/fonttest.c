
#pragma target dragon

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <basic.h>

unsigned s;

unsigned length;

void asm fast(void)
{
    asm {
        pshs    dp,u
        sts     s
        ldu     #$400 // dst
        lds     #$420 // src
        ldd     #8  // length
        std     length

        leau 5,u

        copy_blocks:
        subd #5
        lbmi copy_bytes
        puls x,y,dp
        pshu x,y,dp
        leau 10,u
        bra copy_blocks

        copy_bytes:
        /*
        leau -3,u
        addd #7
        bmi copy_exit
        puls dp
        pshu dp
        */
        /*
        leau 2,u
        subd #1
        bmi copy_exit
        puls dp
        pshu dp
        leau 2,u
        subd #1
        bmi copy_exit
        puls dp
        pshu dp
        leau 2,u
        subd #1
        bmi copy_exit
        puls dp
        pshu dp
        leau 2,u
        subd #1
        bmi copy_exit
        puls dp
        pshu dp
        leau 2,u
        subd #1
        bmi copy_exit
        puls dp
        pshu dp
        leau 2,u
        subd #1
        bmi copy_exit
        puls dp
        pshu dp
        leau 2,u
        */
        copy_exit:
        lds s
        puls dp,u
    }
}

int main(void)
{
    //clrscr();
    //puts("");
    //puts("ABCDEFGFabcdefg");
    //fast();
    //return 0;
    //bgcolor(0);
    textmode(MODE_H0_64X24);
    //_pmode = 3;
    CLIP(0, 0, 256, 192);
    char s[100];
    int i;
    for (;;) {
        for (i = 0; i < 10; i++) {
            gotox((unsigned char)i);
            sprintf(s, "HELLO THERE %d,%d\n", wherex(), wherey());
            cputs(s);
        }
        s[0] = 63;
        cgets(s);
        cputc('\n');
        printf("You entered %s\n", s + 2);
        //CIRCLE(150, 100, 50, 1);
    }
    return 0;
}

