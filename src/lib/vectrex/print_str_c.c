
#include <vectrex.h>

// Print a C string (ends with 0).
void vectrex_print_str_c(int8_t y, int8_t x, char* string)
{
    asm {
        jsr     DP_to_D0
        lda     :y
        ldb     :x
        pshs    U
        ldu     :string

        // -- Print_Str_d --
        jsr     >Moveto_d_7F
        jsr     Delay_1

        stu     Vec_Str_Ptr     // Save string pointer
        ldx     #Char_Table-$20 // Point to start of chargen bitmaps
        ldd     #$1883          // $8x = enable RAMP?
        clr     <VIA_port_a     // Clear D/A output
        sta     <VIA_aux_cntl   // Shift reg mode = 110, T1 PB7 enabled
        ldx     #Char_Table-$20 // Point to start of chargen bitmaps
        LF4A5:
        stb     <VIA_port_b     // Update RAMP, set mux to channel 1
        dec     <VIA_port_b     // Enable mux
        ldd     #$8081
        nop                     // Wait a moment
        inc     <VIA_port_b     // Disable mux
        stb     <VIA_port_b     // Enable RAMP, set mux to channel 0
        sta     <VIA_port_b     // Enable mux
        tst     $C800           // I think this is a delay only
        inc     <VIA_port_b     // Enable RAMP, disable mux
        lda     Vec_Text_Width  // Get text width
        sta     <VIA_port_a     // Send it to the D/A
        ldd     #$0100
        ldu     Vec_Str_Ptr     // Point to start of text string
        sta     <VIA_port_b     // Disable RAMP, disable mux
        bra     LF4CB

        LF4C7:
        lda     A,X             // Get bitmap from chargen table
        sta     <VIA_shift_reg  // Save in shift register
        LF4CB:
        lda     ,U+             // Get next character
        // BPL     LF4C7           // Go back if not terminator
        BNE     LF4C7           // Go back if not terminator
        LDA     #$81
        STA     <VIA_port_b     // Enable RAMP, disable mux
        NEG     <VIA_port_a     // Negate text width to D/A
        LDA     #$01
        STA     <VIA_port_b     // Disable RAMP, disable mux
        CMPX    #Char_Table_End-$20 //      Check for last row
        BEQ     LF50A           // Branch if last row
        LEAX    $50,X           // Point to next chargen row
        TFR     U,D             // Get string length
        SUBD    Vec_Str_Ptr
        SUBB    #$02            //  -  2
        ASLB                    //  *  2
        BRN     LF4EB           // Delay a moment
        LF4EB:
        LDA     #$81
        NOP
        DECB
        BNE     LF4EB           // Delay some more in a loop
        STA     <VIA_port_b     // Enable RAMP, disable mux
        LDB     Vec_Text_Height // Get text height
        STB     <VIA_port_a     // Store text height in D/A
        DEC     <VIA_port_b     // Enable mux
        LDD     #$8101
        NOP                     // Wait a moment
        STA     <VIA_port_b     // Enable RAMP, disable mux
        CLR     <VIA_port_a     // Clear D/A
        STB     <VIA_port_b     // Disable RAMP, disable mux
        STA     <VIA_port_b     // Enable RAMP, disable mux
        LDB     #$03            // $0x = disable RAMP?
        BRA     LF4A5           // Go back for next scan line

        LF50A:
        LDA     #$98
        STA     <VIA_aux_cntl   // T1->PB7 enabled
        JSR     Reset0Ref       // Reset the zero reference

        // --
        PULS    U
    }
}

