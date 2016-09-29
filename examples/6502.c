
extern word regz;
extern word value;

word regz = 0, value;

#pragma options --optimize=1 -machine=coco

asm void test1(void)
{
    /*
        asm {
            .p02
            CLRMEM:  LDA #$00                   // Set up zero value
            TAY                                 // Initialize index pointer
            CLRM1:   STA (TOPNT),Y              // Clear memory location
            INY                                 // Advance index pointer
            DEX                                 // Decrement counter
            BNE CLRM1                           // Not zero, continue checking
            RTS                                 // Return
            .p09
        }
        */
}

void test(void)
{
    asm {
        .p02

        lda     #0
        sta     _value
        lda     #$04
        sta     _value+1

        ldy     #0
        loop:
        lda     #0
        sta     (_value),y
        iny
        bne     loop

        lda     #45
        asl     a
        sta     1024
        sta     1025
        inc     1024

        .p09
    }
}

int main(void)
{
    test();
    return 0;
}

