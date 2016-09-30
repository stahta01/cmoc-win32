
// Note: These are not working rountines. Its only the start of a 6502->6809 translator.
// Im just testing that the code is actually converting to something.

#pragma options --optimize=0 -machine=coco

/*
asm void test1(void)
{
    asm {
        .p02
        CLRMEM:  LDA =$00                       // Set up zero value
        TAY                                     // Initialize index pointer
        CLRM1:   STA (TOPNT),Y                  // Clear memory location
        INY                                     // Advance index pointer
        DEX                                     // Decrement counter
        BNE CLRM1                               // Not zero, continue checking
        RTS                                     // Return
TOPNT:
        fdb 0
        .p09
    }
}

asm void test2(void)
{
    asm {
        .p02
        MULT10:
        ASL                                     // multiply by 2
        STA TEMP                                // temp store in TEMP
        ASL                                     // again multiply by 2 (*4)
        ASL                                     // again multiply by 2 (*8)
        CLC
        ADC TEMP                                // as result, A = x*8 + x*2
        RTS
        TEMP:
        fcb 0
        .p09
    }
}

asm void test3(void)
{
    asm {
// 32 bit multiply with 64 bit product
        .p02
        MULTIPLY:  lda     #$00
        sta     PROD+4                          // Clear upper half of
        sta     PROD+5                          // product
        sta     PROD+6
        sta     PROD+7
        ldx     #$20                            // Set binary count to 32
        SHIFT_R:   lsr     MULR+3               // Shift multiplyer right
        ror     MULR+2
        ror     MULR+1
        ror     MULR
        bcc     ROTATE_R                        // Go rotate right if c = 0
        lda     PROD+4                          // Get upper half of product
        clc                                     // and add multiplicand to
        adc     MULND                           // it
        sta     PROD+4
        lda     PROD+5
        adc     MULND+1
        sta     PROD+5
        lda     PROD+6
        adc     MULND+2
        sta     PROD+6
        lda     PROD+7
        adc     MULND+3
        ROTATE_R:  ror     a                    // Rotate partial product
        sta     PROD+7                          // right
        ror     PROD+6
        ror     PROD+5
        ror     PROD+4
        ror     PROD+3
        ror     PROD+2
        ror     PROD+1
        ror     PROD
        dex                                     // Decrement bit count and
        bne     SHIFT_R                         // loop until 32 bits are
        clc                                     // done
        lda     MULXP1                          // Add dps and put sum in MULXP2
        adc     MULXP2
        sta     MULXP2
        rts
        PROD: fdb 0
        fdb 0
        MULND: fdb 0
        fdb 0
        MULR: fdb 0
        fdb 0
        MULXP1: fdb 0
        MULXP2: fdb 0
        MULXP2L: fdb 0
        .p09
    }
}
*/

extern byte memory;

byte memory;

void test0(void)
{
    asm {
        ldd     =0
        std     15
        .p02
        lda     =$00
        sta     0
        lda     =$04
        sta     1
        ldy     =0
        lda     =0
        ldx     :memory
        .p09
    }
}

int main(void)
{
    test0();
    return 0;
}

