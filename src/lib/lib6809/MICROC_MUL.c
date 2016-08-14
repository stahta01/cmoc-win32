
void asm __MICROC_MUL(void)
{
    asm {
        MICROC_MUL: export

        MICROC_MUL:     // 16 bit Multiply: D = X * D
        pshs    D,X     // Save parameters
        lda     1,S     // Get low of parm 1
        ldb     3,S     // And low of parm 2
        mul             // Multiply to get result
        pshs    A,B     // Save result
        lda     2,S     // Get high of parm 1
        ldb     5,S     // And low of parm 2
        mul             // Multiply to get result
        addb    ,S      // Add to high of previous result
        stb     ,S      // And resave
        lda     3,S     // Get low of parm 1
        ldb     4,S     // And high of parm 2
        mul             // Multiply to get result
        addb    ,S      // Add to result
        stb     ,S      // And resave
        puls    A,B     // Get result from stack
        leas    4,S     // Drop saved parameters
    }
}


