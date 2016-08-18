
// Enable main interrupt

void asm enable(void)
{
    asm {
        andcc   #%11101111 // Clear IRQ mask
    }
}



