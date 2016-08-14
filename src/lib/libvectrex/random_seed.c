
#include <vectrex.h>

// The Vectrex uses three bytes for the random seed.
void random_seed(uint8_t seed1, uint8_t seed2, uint8_t seed3)
{
    asm {
        LDA  seed1
        STA  Vec_Seed_Ptr+0
        LDA  seed2
        STA  Vec_Seed_Ptr+1
        LDA  seed3
        STA  Vec_Seed_Ptr+2
    }
}

