
int _static_count1, _static_count2;

asm int irq_disable(void)
{
    asm {
        ldd     _static_count1
        subd    #1
        bne     skip
        sei
        skip:
        std     _static_count1
    }
}

asm int irq_enable(void)
{
    asm {
        ldd     _static_count1
        bne     irq_enable_skip
        cli
        irq_enable_skip:
        addd    #1
        std     _static_count1
    }
}

