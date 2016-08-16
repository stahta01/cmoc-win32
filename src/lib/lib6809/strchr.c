
// Note that CMOC passes a character value(e.g., 'x')
// as a word to a function.

unsigned asm strchr(char* s, int c)
{
    asm {
        pshs    x
        ldx     4,s         // string
        lda     7,s         // char to search for (ignore MSB)

        strchr_100:
        cmpa    ,x
        beq     strchr_800 // found
        tst     ,x+
        bne     strchr_100

        clra                // not found: return NULL
        clrb
        bra     strchr_900

        strchr_800:
        tfr     x,d         // return address where char found

        strchr_900:
        puls    x,pc
    }
}


