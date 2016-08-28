
#pragma target dragon

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <basic.h>

unsigned memcpy_stack;

void asm memcpy_fast(void* dst, void* src, size_t len)
{
    asm {
        ldx     2,s             // dst
        ldy     4,s             // src
        ldd     6,s             // len

        cmpd    #9
        bhi     memcpy_copyx
        beq     memcpy_copy9
        cmpd    #7
        bhi     memcpy_copy8
        beq     memcpy_copy7
        cmpd    #5
        bhi     memcpy_copy6
        beq     memcpy_copy5
        cmpd    #3
        bhi     memcpy_copy4
        beq     memcpy_copy3
        cmpd    #1
        bhi     memcpy_copy2
        beq     memcpy_copy1
        rts

        memcpy_copy9:
        lda     8,y
        sta     8,x
        memcpy_copy8:
        ldd     6,y
        std     6,x
        ldd     4,y
        std     4,x
        ldd     2,y
        std     2,x
        ldd     0,y
        std     0,x
        rts

        memcpy_copy7:
        lda     6,y
        sta     6,x
        memcpy_copy6:
        ldd     4,y
        std     4,x
        ldd     2,y
        std     2,x
        ldd     0,y
        std     0,x
        rts

        memcpy_copy5:
        lda     4,y
        sta     4,x
        memcpy_copy4:
        ldd     2,y
        std     2,x
        ldd     0,y
        std     0,x
        rts

        memcpy_copy3:
        lda     2,y
        sta     2,x
        memcpy_copy2:
        ldd     0,y
        std     0,x
        rts

        memcpy_copy1:
        lda     0,y
        sta     0,x
        rts

        memcpy_copyx:
        pshs    dp,u
        sts     memcpy_stack
        leau    5,x
        leas    ,y
        subd    #5

        memcpy_copyx_loop:
        puls    x,y,dp
        pshu    x,y,dp
        leau    10,u
        subd    #5
        bpl     memcpy_copyx_loop

        incb
        beq     memcpy_copyx4
        incb
        beq     memcpy_copyx3
        incb
        beq     memcpy_copyx2
        incb
        beq     memcpy_copyx1

        memcpy_copyx0:
        lds     memcpy_stack
        puls    dp,u,pc

        memcpy_copyx4:
        ldd     2,s
        std     -3,u
        memcpy_copyx2:
        ldd     0,s
        std     -5,u
        bra     memcpy_copyx0

        memcpy_copyx3:
        ldd     1,s
        std     -4,u
        memcpy_copyx1:
        lda     0,s
        sta     -5,u
        bra     memcpy_copyx0
    }
}

int main(void)
{
    for (int l = 0; l <= 26; l++) {
        clrscr();
        puts(">--------------------------");
        puts(">ABCDEFGHIJKLMNOPQRSTUVWXYZ");
        memcpy_fast(0x401, 0x421, l);
        getch();
    }
    return 0;
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

