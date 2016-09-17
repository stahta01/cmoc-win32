
#include <vectrex.h>

// Print a C string (ends with 0).
void print_str_c(int8_t y, int8_t x, char* string)
{
    asm {
        JSR     DP_to_D0
        LDA     :y
        LDB     :x
        PSHS    U
        LDU     :string

        // -- Print_Str_d --
        JSR     >Moveto_d_7F
        JSR     Delay_1

        STU     Vec_Str_Ptr     // Save string pointer
        LDX     #Char_Table-$20 // Point to start of chargen bitmaps
        LDD     #$1883          // $8x = enable RAMP?
        CLR     <VIA_port_a     // Clear D/A output
        STA     <VIA_aux_cntl   // Shift reg mode = 110, T1 PB7 enabled
        LDX     #Char_Table-$20 // Point to start of chargen bitmaps
        LF4A5:
        STB     <VIA_port_b     // Update RAMP, set mux to channel 1
        DEC     <VIA_port_b     // Enable mux
        LDD     #$8081
        NOP                     // Wait a moment
        INC     <VIA_port_b     // Disable mux
        STB     <VIA_port_b     // Enable RAMP, set mux to channel 0
        STA     <VIA_port_b     // Enable mux
        TST     $C800           // I think this is a delay only
        INC     <VIA_port_b     // Enable RAMP, disable mux
        LDA     Vec_Text_Width  // Get text width
        STA     <VIA_port_a     // Send it to the D/A
        LDD     #$0100
        LDU     Vec_Str_Ptr     // Point to start of text string
        STA     <VIA_port_b     // Disable RAMP, disable mux
        BRA     LF4CB

        LF4C7:
        LDA     A,X             // Get bitmap from chargen table
        STA     <VIA_shift_reg  // Save in shift register
        LF4CB:
        LDA     ,U+             // Get next character
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

