
// Disable main interrupt

void asm disable(void)
{
    asm {
        orcc    #%00010000                  // Set IRQ mask
    }
}

