
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <conio.h>
#include <equates.h>

#define LOAD1   lda ,u+
#define SAVE1   sta ,x+
#define LOAD2   ldd ,u++
#define SAVE2   std ,x++

#define AWORD(X)    X*2,s

#define ADST    2,s
#define ASRC    4,s
#define ANUM    6,s

unsigned safe;

void asm memcpy2(void* dst, void* src, unsigned n)
{
    asm {
        ldy     ANUM
        beq     LEXIT
        ldx     ADST
#ifdef ASRC
        stu     safe
        ldu     ASRC
#endif
#ifdef ACHR
        lda     1+ACHR
#endif
        ldb     1+ANUM
        andb    #7
        beq     LCOPY8
        negb
        leay    b,y
        negb
        LCOPY1:
        LOAD1
        SAVE1
        decb
        bne     LCOPY1
        cmpy    #0
        beq     LRESTORE
        LCOPY8:
        tfr     a,b
        LLOOP8:
        LOAD2
        SAVE2
        LOAD2
        SAVE2
        LOAD2
        SAVE2
        LOAD2
        SAVE2
        leay    -8,y
        bne     LLOOP8
        LRESTORE:
#ifdef ASRC
        ldu     safe
#endif
        LEXIT:
        ldd     ADST
    }
}

int main(void)
{
    clrscr();
    getch();
    puts("abcdefghijklmnopqrstuvwxyz");
    puts("--------------------------");
    clock_t t = clock();
    for (unsigned i = 0; i < 8000; i++) {
        memcpy16(0x400, 0x400, 32);
        //      printf("OUT=%u\n", *(unsigned*)_V42);
        //memset(0x400, i, 32 * 16);
    }
    printf("%d\n", clock() - t);

    return 0;
}

