
// Note: These are not working rountines. Its only the start of a 6502->6809 translator.
// Im just testing that the code is actually converting to something.

#pragma options --optimize=0 -machine=coco

extern byte memory;

byte memory;

void test0(void)
{
    asm {
        ldd     #0
        std     15
        .p02
        lda     #$00
        sta     0
        lda     #$04
        sta     1
        ldy     #0
        loop:
        sta     (0),y
        iny
        bne     loop
        .p09
    }
}

int main(void)
{
    test0();
    return 0;
}

