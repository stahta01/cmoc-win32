
// Returns 0 if no key is currently pressed.
//
unsigned char asm inkey()
{
    asm {
        jsr     [$A000]     // POLCAT
        tfr     a,b         // byte return value goes in B
    }
}


